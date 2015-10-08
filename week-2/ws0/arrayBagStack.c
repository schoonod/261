//
//  arrayBagStack.c
//  w2, ws0
//
//  Created by Dane Schoonover on 10/7/15.
//  Copyright (c) 2015 Dane. All rights reserved.
//

#include "arrayBagStack.h"

//In this worksheet we will construct a simple BAG and STACK abstraction on top of an
//array. Assume we have the following interface file (arrayBagStack.h) :


void initArray (struct arrayBagStack * b) {
    for (int i = 0; i < sizeof(b->data); i++) {
        b->count = 0;
    }
}


/* Bag Interface Functions */
void addArray (struct arrayBagStack * b, TYPE v) {
    if (b->count <= 100) {
        for (int i = 0; i < b->count; i++){
            if (b->data[i] == 0){
                b->data[i] = v;
                b->count++;
                return;
            }
        }
    }
}

int containsArray (struct arrayBagStack * b, TYPE v) {
    for (int i = 0; i < b->count; i++) {
        if (b->data[i] == v)
            return 1;
    }
    
    return 0;
}

void removeArray (struct arrayBagStack * b, TYPE v) {
    for (int i = 0; i < b->count; i++) {
        if (b->data[i] == v){
            b->data[i] = 0;
            b->count--;
            return;
        }
    }
}

int sizeArray (struct arrayBagStack * b) {
    return b->count;
}



/* Stack Interface Functions */
void pushArray (struct arrayBagStack * b, TYPE v) {
    b->data[b->count] = v;
    b->count++;
}

TYPE topArray (struct arrayBagStack * b) {
    return b->data[b->count - 1];
}

void popArray (struct arrayBagStack * b) {
    b->data[b->count] = 0;
    b->count--;
}

int isEmptyArray (struct arrayBagStack * b) {
    if (b->count == 0)
        return 1;
    else
        return 0;
}



//A Better Solution…
//This solution has one problem.  The arrayBagStack structure is in the .h file and therefore exposed to the users of
//the data structure.   How can we get around this problem?  Think about it…we’ll return to this question soon.








