// Author: Dane Schoonover
// Date Created: 10/9/2015
// Last Modification Date: 0/9/2015
// File name: Q0.c
// Overview:
//    This program dynamically allocates memory for an array, fills it
//    with values, prints it, sorts it, and prints the sorted version.
// Input:
//    This program has no input.
// Output:
//    The output is the unsorted and sorted version of the array.

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n) {
    // Sort the given array number, of length n
    // Citation: The C Programming Language (Kernighan and Ritchie), pg. 55, shell sort
    int gap;
    int temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i-gap; j>=0 && number[j] > number[j+gap]; j-=gap) {
                temp = number[j];
                number[j] = number[j+gap];
                number[j+gap] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int* array = malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < 20; i++){
        array[i] = rand();
    }

    /*Print the contents of the array.*/
    for (int i = 0; i < 20; i++){
        printf("%d\n", array[i]);
    }

    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);

    /*Print the sorted contents of the array.*/
    for (int i = 0; i < 20; i++){
        printf("%d\n", array[i]);
    }

    return 0;
}
