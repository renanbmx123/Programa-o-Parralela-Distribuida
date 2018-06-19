
#include "ordenation.h"

// Bubble sort function
void bs(int n, int * vetor)
{
    int c=0, d, troca, trocou =1;


    while ((c < (n-1)) & trocou )
        {
        trocou = 0;
        for (d = 0 ; d < n - c - 1; d++)
            if (vetor[d] > vetor[d+1])
                {
                troca      = vetor[d];
                vetor[d]   = vetor[d+1];
                vetor[d+1] = troca;
                trocou = 1;
                }
        c++;
        }
}

/*********** Used for Quick Sort function ********************
 *************************************************************
 *
 * USAGE: 
 * ---- qsort(*vector, lenght, sizeof , compare);
 * ------------------------------------------------------------
 * PARAMETERS:
 * ---- *vector: is the pointer vector to ordenate
 * ---- lenght: The lenght of vector
 * ---- sizeof: The size in bytes of a vector
 * ---- compare: Is a function to pass 
 * ------------------------------------------------------------
***************************************************************/ 
int compare(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}
