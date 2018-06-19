/*INTERLEAVING HEADER********************************************************
* FILENAME :        
*
* DESCRIPTION :
*       
*
* PUBLIC FUNCTIONS :
*       
* AUTHOR :    Renan&Thomaz        START DATE :    15 JUn 2018
*
*INTERLEAVING HEADER*/
#ifndef INTERLEAVING
#include <stdlib.h>
#include <mpi.h>

int *interleaving(int vetor[], int tam);
void merge(int*output, int* vector1, int size1, int* vector2, int size2, int* vector3, int size3);
int valid(int index, int limit);
int higher_or_invalid(int array[], int value_index, int limit, int other_value_index);
int left_child(int index);
int right_child(int index);
int parent(int index);
int is_leaf(int current_size, int total_size, int number_of_process);
//int is_leaf3(int current_size, int total_size, int number_of_process);

#endif