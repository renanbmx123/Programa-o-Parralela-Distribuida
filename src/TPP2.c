/* This includes are locate in "inc" folder*/
#include "main.h"
/*---------------------------------------*/

//This function order a vector that is passed through his childs and going back interleaving of this vector
int* order(int my_rank, int array[], int size, MPI_Status status)
{
	int half_size = size / 2;

	// Send array
	MPI_Send(array, half_size,
			MPI_INT, left_child(my_rank), SEND_DOWN_TAG,
			MPI_COMM_WORLD);

	MPI_Send(array + half_size, half_size,
			MPI_INT, right_child(my_rank), SEND_DOWN_TAG,
			MPI_COMM_WORLD);

	// Receive response
	MPI_Recv(array, half_size,
			MPI_INT, left_child(my_rank), SEND_UP_TAG,
			MPI_COMM_WORLD, &status);

	MPI_Recv(array + half_size, half_size,
			MPI_INT, right_child(my_rank), SEND_UP_TAG,
			MPI_COMM_WORLD, &status);

	return interleaving(array, size);
}

int main(int argc, char** argv){

    int i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &proc_n);   
    
	t1 = MPI_Wtime(); //Starting counting the time

    if (my_rank == 0)
    {
		/* Initialize the array*/
        int array[ARRAY_SIZE] ;
		/* fill the array*/
		/*for (i = 0; i < ARRAY_SIZE; i++)
			array[i] = ARRAY_SIZE - i;
*/
		/* Divede or conquer ?*/
		if(ARRAY_SIZE <= DELTA)
		{
			
    		for (i = 1; i < proc_n; i++) { 
        			MPI_Send(0, 0, MPI_INT, i, DIED_TAG, MPI_COMM_WORLD);
    		}			
			#ifdef BSORT
				bs(size, array);
			#endif

			#ifdef QSORT
				bs(size, array);
			#endif
		}
		else{
			for (i = 1; i < proc_n; i++) {
	        	MPI_Send(0, 0, MPI_INT, i, WORK, MPI_COMM_WORLD);
    		}		 
		order(my_rank, array, ARRAY_SIZE, status);
			//int *result = order(my_rank, array, ARRAY_SIZE, status);
		}
    }
    else    //Im a slave 
    {
        int size;
	MPI_Recv(0, 0, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
	

		if(status.MPI_TAG != DIED_TAG){
			MPI_Probe(parent(my_rank), SEND_DOWN_TAG, MPI_COMM_WORLD, &status);
			MPI_Get_count(&status, MPI_INT, &size);
			
			int *array = calloc(size, sizeof(int));
			MPI_Recv(array, size, MPI_INT, parent(my_rank), SEND_DOWN_TAG, MPI_COMM_WORLD,&status);

	    	
			if(is_leaf(size, ARRAY_SIZE, proc_n))
			{
				#ifdef BSORT
					bs(size, array);
				#endif

				#ifdef QSORT
					bs(size, array);
				#endif
				MPI_Send(array, size, MPI_INT, parent(my_rank), SEND_UP_TAG, MPI_COMM_WORLD);
			}
			else
			{
				array = order(my_rank, array, size, status);
				MPI_Send(array, size, MPI_INT, parent(my_rank), SEND_UP_TAG, MPI_COMM_WORLD);
			}
		}
     
    }
	if(my_rank == 0)
	{
    		t2 = MPI_Wtime(); //Stop counting the time
	    	printf("Execution time :%fs\n",t2-t1);
	 }
	MPI_Finalize();    
    return 0;
}
