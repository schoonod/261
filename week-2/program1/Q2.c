// Author: Dane Schoonover
// Date Created: 10/9/2015
// Last Modification Date: 0/9/2015
// File name: Q0.c
// Overview:
//    This program demonstrates passing values by reference and by values.
// Input:
//    This program has no input.
// Output:
//    The output will be the values modified by the function used to demonstrate
//    pass by value and pass by reference.

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("x=%d, y=%d, z=%d\n", x, y, z);


    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);


    /*Print the value returned by foo*/
    printf("%d\n", foo(&x, &y, z));

    /*Print the values of x, y and z again*/
    printf("x=%d, y=%d, z=%d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    // No, because a pointer was not passed and thus z was passed by value, meaning a copy was made, not the actual z.

    return 0;
}
