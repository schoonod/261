// Author: Dane Schoonover
// Date Created: 10/9/2015
// Last Modification Date: 0/9/2015
// File name: Q0.c
// Overview:
//    This program prints pointer addresses and values.
// Input:
//    This program has no input.
// Output:
//    The output will be the value pointed to by the pointer used, the address
//    it points to, and the address of the pointer itself.

#include <stdio.h>
#include <stdlib.h>

void fooA(int *iptr){
     /*Print the value pointed to by iptr*/
    printf("%i\n", *iptr);

     /*Print the address pointed to by iptr*/
    printf("%p\n", iptr);

     /*Print the address of iptr itself*/
    printf("%p\n", &iptr);
}

int main(){

     /*declare an integer x*/
    int x;

     /*print the address of x*/
    printf("%p\n", &x);

     /*Call fooA() with the address of x*/
    fooA(&x);

     /*print the value of x*/
    printf("%i\n", x);

    return 0;
}
