#include "interleaving.h"


/*Chamada para a rotina de Intercalação

int *vetor_auxiliar;         // ponteiro para o vetor resultantes que sera alocado dentro da rotina 

vetor_aux = interleaving(vetor, tam);
*/
int *interleaving(int vetor[], int tam)
{
	int *vetor_auxiliar;
	int i1, i2, i_aux;

	vetor_auxiliar = (int *)malloc(sizeof(int) * tam);

	i1 = 0;
	i2 = tam / 2;

	for (i_aux = 0; i_aux < tam; i_aux++) {
		if (((vetor[i1] <= vetor[i2]) && (i1 < (tam / 2)))
		    || (i2 == tam))
			vetor_auxiliar[i_aux] = vetor[i1++];
		else
			vetor_auxiliar[i_aux] = vetor[i2++];
	}

	return vetor_auxiliar;
}

void merge(int*output, int* vector1, int size1, int* vector2, int size2, int* vector3, int size3)
{
int i, j, k, m;
i = j = k = m = 0;

while(i <size1+size2+size3)
    if (j < size1 ) 
        if(k < size2)
            if(m<size3)
                if(vector1[j] < vector2[k])
                    if(vector1[j] < vector3[m]) 
                        output[i++] = vector1[j++];
                    else
                        if(vector3[m] < vector2[k])
                            output[i++] = vector3[m++]; 
                        else
                            output[i++] = vector2[k++];
                else
                    if(vector2[k] < vector3[m])
                        output[i++] = vector2[k++]; 
                    else
                        output[i++] = vector3[m++];
            else
                if(vector1[j] < vector2[k])
                    output[i++] = vector1[j++]; 
                else
                    output[i++] = vector2[k++];
        else 
            if(m<size3)
                if(vector1[j] < vector3[m]) 
                    output[i++] = vector1[j++];
                else
                    output[i++] = vector3[m++];
            else
                output[i++] = vector1[j++];
    else
        if(k<size2)
            if(m<size3)
                if(vector2[k] < vector3[m]) 
                    output[i++] = vector2[k++];
                else
                    output[i++] = vector3[m++];
            else
                output[i++] = vector2[k++];
        else
            output[i++] = vector3[m++];
}

int valid(int index, int limit) {
	return index < limit;
}

int higher_or_invalid(int array[], int value_index, int limit, int other_value_index) {
	return (array[value_index] > array[other_value_index]) || value_index >= limit;
}

int left_child(int index) {
	return 2 * index + 1;
}

int right_child(int index) {
	return 2 * index + 2;
}

int parent(int index) {
	return (index - 1) / 2;
}

int is_leaf(int current_size, int total_size, int number_of_process) {
	return current_size <= total_size / ((number_of_process + 1) / 2);
}

/*int is_leaf3(int current_size, int total_size, int number_of_process) {
//	printf("current size: %d, total_size: %d, delta: %d\n", current_size, total_size, (total_size / number_of_process));
	return current_size < (total_size / number_of_process) * 2;
}*/

