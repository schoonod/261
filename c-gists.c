/*
Table of Contents
  Data Structures
    Bag implemetation
    Stack implementation
    Dynamic array resizing
  Abstract Data Types
    array
    dynamicArray
  Sorting
    quickSort
    mergeSort
    shellSort
    bubbleSort
  String Manipulation
    toUpper
    toLower
    oddEven
    caseCheck
*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
// @DATA STRUCTURES
/******************************************************************************/
/******************************************************************************/
// @Bag
/******************************************************************************/
/******************************************************************************/
// @Stack
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
// @ABSTRACT DATA TYPES
/******************************************************************************/
/******************************************************************************/
// @Array
/******************************************************************************/
/******************************************************************************/
// @dynamicArray
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
// @SORTING
/******************************************************************************/
/******************************************************************************/
// @QuickSort
/******************************************************************************/
void quickSort (double storage [ ], int n) {
 quickSortInternal (storage, 0, n-1); }

void quickSortInternal (double storage [ ], int low, int high) {
 if (low >= high) return; // base case
 int pivot = (low + high)/2; // one of many techniques
 pivot = partition(storage, low, high, pivot);
 quickSortInternal (storage, low, pivot-1); // first recursive call
 quickSortInternal (storage, pivot+1, high); // second recursive call
 }


/******************************************************************************/
// @MergeSort
/******************************************************************************/

void mergeSort (double data [ ], int n) {
 double * temp = (double *) malloc (n * sizeof(double));
 assert (temp != 0); /* make sure allocation worked */
 mergeSortInternal (data, 0, n-1, temp);
 free (temp);
 }

void mergeSortInternal (double data [ ], int low, int high, double temp [ ]) {
 int i, mid;
 if (low >= high) return; /* base case */
 mid = (low + high) / 2;
 mergeSortInternal(data, low, mid, temp); /* first recursive call */
 mergeSortInternal(data, mid+1, high, temp); /* second recursive call */
 merge(data, low, mid, high, temp); /* merge into temp */
 for (i = low; i <= high; i++) /* copy merged values back */
 data[i] = temp[i];
}


/******************************************************************************/
// @ShellSort
/******************************************************************************/
void sort(int* number, int n) {
    // Sort the given array number, of length n
    // Citation, The C Programming Language (Kernighan, Ritchie), pg. 55, shell sort
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
/******************************************************************************/
// @BubbleSort
/******************************************************************************/
void bubbleSort (double data [ ], int n) {
  for (int i = n-1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      // data[j] is largest value in 0 .. j
      if (data[j] > data[j+1])
      swap(data, j, j+1)
      // data[j+1] is largest value in 0 .. j+1
    }
    data[i] is largest value in 0 .. i
  }
  // array is sorted
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/******************************************************************************/
// STRING MANIPULATION
/******************************************************************************/
/******************************************************************************/
// @toUpper - Convert ch to upper case, assuming it is in lower case currently
/******************************************************************************/
char toUpperCase(char ch){
     return ch-'a'+'A';
}
/******************************************************************************/
// @toLower - Converts ch to lower case, assuming it is in upper case currently
/******************************************************************************/
char toLowerCase(char ch){
     return ch-'A'+'a';
}
/******************************************************************************/
// @oddEven - Check if even or odd
/******************************************************************************/
if (x % 2) // x is odd if true
else       // x is even
/******************************************************************************/
// @caseCheck - Check uppercase/lowercase ANSI
/******************************************************************************/
if (word[i] >= 'A' && word[i] <= 'Z')
else if (word[i] >= 'a' && word[i] <= 'z')
