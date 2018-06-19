/*MAIN HEADER****************************************************************
* FILENAME :        ordenation.h
*
* DESCRIPTION :
*       
* PUBLIC FUNCTIONS :
*       
* AUTHOR :    Renan&Thomaz        START DATE :    15 JUn 2018
* 
*MAIN HEADER*/
#ifndef MAIN

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include "ordenation.h"
#include "interleaving.h"



#define ARRAY_SIZE 1000000000   // SIZE and Columns of a matrix
/* Tags for message control*/

#define SEND_UP_TAG   1
#define SEND_DOWN_TAG 2
#define DIED_TAG      3
#define WORK          4
#define DEBUG         5

/*-------------------------*/
/* Defines a type of algorithm for ordenation */

//#define BSORT_TAG 1
#define QSORT_TAG 2
/*------------------------*/
#define DELTA 250 000 000 // Max number for conquer the array 7 process leaf only 
//#define DELTA 250 000 000 // Max number for conquer the array 15 process leaf only
//#define DELTA 250 000 000 // Max number for conquer the array 31 process leaf only

/* Variables used in main program */
//int array[ARRAY_SIZE];
double t1, t2;          // This two double is used for messure the time of the holl process
int my_rank;
int proc_n;
size_t vsize;
MPI_Status status;
/*--------------------------------------------*/

#endif