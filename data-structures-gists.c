/*
Table of Contents
    Data Structures
        dynamicArray
				linkedList
    Abstract Data Types w/ Implementation
        Bags
            bagDynamicArray
        Stacks
            stackDynamicArray
						stackLinkedList
				Queue
						queueLinkedList
						queueDynamicArray
				Deque
						dequeuFloatingDynamicArray
						dequeDoublyLinkedList
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


/*------------------------------------------------------------------------------------------------------------*/
// @DATA STRUCTURES
/*------------------------------------------------------------------------------------------------------------*/
///////////////////
// @dynamicArray //
///////////////////
/*
.h symbolic constant:
    # ifndef TYPE
    # define TYPE int
    ...
    ...
    # endif
*/

struct DynArr {
	TYPE *data;		  /* pointer to the data array */
	int size;		    /* Number of elements in the array */
	int capacity;		/* capacity of the array */
};

void initDynArr(struct DynArr *v, int capacity) {
	v->data = malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
}

void freeDynArr(struct DynArr *v) {
	if(v->data != 0) {
		free(v->data); 	  /* free the space on the heap */
		v->data = 0;   	  /* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

int sizeDynArr( struct DynArr *v) {
	return v->size;
}

void addVal(struct DynArr *v, TYPE val) {
	/* Check to see if a resize is necessary */
	if(v->size >= v->capacity)
		_setCapDynArr(v, 2 * v->capacity);
	v->data[v->size] = val;
	v->size++;
}

void _setCapDynArr(struct DynArr *v, int newCap) {
  struct DynArr new;
  initDynArr(&new, newCap);
  for (int i = 0; i < v­->size; i++) {
    new.data[i] = v­->data[i];
  }
  new.size = v->size;
  freeDynArr(v);
}

TYPE getDynArr (struct DynArr * da, int position) {
    assert(da->size <= position);
    return da->data[position];
}

void putDynArr(struct DynArr * da, int position, TYPEvalue) {
    assert(position < da->capacity);
    da->data[position] = TYPEvalue;
}

// Swap two array positions
void swapDynArr (struct DynArr * da, int i, int j) {
    assert((i>=0 && i < da->size) && (j >=0 && j < da->size));
    TYPE temp;
    temp = da->data[i];
    da->data[i] = da->data[j];
    da->data[j] = temp;
}

// Removes the value held at a specific location and moves remaining elements
// left 1
void _dynArrayRemoveAt (struct DynArr * da, int index) {
    assert(index >=0 && index < da->size);
    da->data[index] = NULL;
    // move the remaining values back
    for(index; index < da->size; index++) {
   	  da->data[index] = da->data[index+1];
    }
    da->size = index;
}

/////////////////
// @linkedList //
/////////////////
struct Link {
	TYPE val;
	struct Link *next;
}
/*------------------------------------------------------------------------------------------------------------*/
// @ABSTRACT DATA TYPES WITH IMPLEMENTATIONS
/*------------------------------------------------------------------------------------------------------------*/
//////////////////////
// @bagDynamicArray //
//////////////////////
/*
.h macro for generalized container:
    # ifndef EQ
    # define EQ(a, b) (a == b)
    ...
    ...
    # endif

*/

void addDynArray (struct DynArr * da, TYPE e) {
    if(da->size <= da->capacity){
   	  addDynArr(da, e);
    } else{
   	  _setCapacityDynArr(da); //doubles capacity according to comment above
   	  addDynArr(da, e);
    }
}

int containsDynArr (struct DynArr * da, TYPE e) {
  for(int i=0; i <= da->size; i++){
   	 if(da->data[i] == e)
   		 return 1;
  }
  return 0;
}

void removeDynArr (struct DynArr * dy, TYPE test) {
  int i;
  for (i = 0; i < dy->size; i++) {
    if (EQ(test, dy->data[i])) { /* found it */
    _dynArrayRemoveAt(dy, i);
    return;
    }
  }
}

int sizeArray (struct arrayBagStack * b) {
    return b->count;
}

///////////////////////
// @stackDynamicArray //
///////////////////////
// Add to top of array
void pushDynArray (struct DynArr * da, TYPE e) {
    if(da->size <= da->capacity){
   	  addDynArr(da, e);
    } else{
   	  _setCapacityDynArr(da); //doubles capacity according to comment above
   	  addDynArr(da, e);
    }
}

// Remove from top of array
void popDynArray (struct DynArr * da) {
    removeAtDynArr(da,da->size);
    da->size--;
}

// Return top of array
TYPE topDynArray (struct DynArr * da) {
  assert (sizeDynArr(da) > 0);
  return getDynArr (da, sizeDynArr(da) -1);
}

int isEmptyDynArray (struct DynArr * da) {
    if(da->size == 0)
   	 return 1;
    else
   	 return 0;
}

//////////////////////
// @stackLinkedList //
//////////////////////
struct StackLinkedList {
	struct link *firstLink;
}

struct stackInitLinkedList (stackLinkedList s) {
	s->firstLink = 0;
}

void pushListStack(struct ListStack *s, TYPE d){
	struct Link *newLink = malloc...;
	assert..
	newLink->val = d;
	newLink->next = s->firstLink;
	s->firstLink = newLink;
	// allocate a new link
	// set new link value
	// set new link pointer to previous link
	// change head to point to the new link
}


/////////////////////////////////
// @dequeuFloatingDynamicArray //
/////////////////////////////////
struct deque {
	TYPE * data;
 	int capacity;
 	int size;
 	int start;
};

void dequeInit (struct deque *d, int initCapacity) {
 	d->size = d->start = 0;
 	d->capacity = initCapacity; assert(initCapacity > 0);
 	d->data = (TYPE *) malloc(initCapacity * sizeof(TYPE));
 	assert(d->data != 0);
}

int dequeSize (struct deque *d) {
	return d->size;
}

void _dequeSetCapacity (struct deque *d, int newCap) {
	int i;
	/* Create a new underlying array*/
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);
	/* Copy elements to new array */
	int j = d->start;
		for(i = 0; i < d->size; i++) {
			newData[i] = d->data[j];
			j++;
			if(j >= d->capacity)
			j = 0;
		}
	/*  Delete the old array*/
	free(d->data);
	/* update capacity and size and data*/
	d->data = newData;
	d->capacity = newCap;
	d->beg = 0;
}

void dequeAddFront (struct deque *d, TYPE newValue) {
	if (d->size >= d->capacity) {
		_dequeSetCapacity(d, 2*d->capacity);
	}
}

void dequeAddBack (struct deque *d, TYPE newValue) {
 	if (d->size >= d->capacity) {
		_dequeSetcapacity(d, 2* d->capacity);
	}
}


void dequeFree (struct deque *d) {
 	free(d->data);
 	d->size = 0;
 	d->capacity = 0;
}

/*------------------------------------------------------------------------------------------------------------*/
// @SORTING
/*------------------------------------------------------------------------------------------------------------*/
////////////////
// @QuickSort //
////////////////
void quickSort (double storage [ ], int n) {
 quickSortInternal (storage, 0, n-1); }

void quickSortInternal (double storage [ ], int low, int high) {
 if (low >= high) return; // base case
 int pivot = (low + high)/2; // one of many techniques
 pivot = partition(storage, low, high, pivot);
 quickSortInternal (storage, low, pivot-1); // first recursive call
 quickSortInternal (storage, pivot+1, high); // second recursive call
 }

////////////////
// @MergeSort //
////////////////
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

// needs final merge function

////////////////
// @ShellSort //
////////////////
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
/////////////////
// @BubbleSort //
/////////////////
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

/*------------------------------------------------------------------------------------------------------------*/
// STRING MANIPULATION
/*------------------------------------------------------------------------------------------------------------*/
// @toUpper - Convert ch to upper case, assuming it is in lower case currently /
char toUpperCase(char ch){
     return ch-'a'+'A';
}

// @toLower - Converts ch to lower case, assuming it is in upper case currently/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

// @oddEven - Check if even or odd //
if (x % 2) // x is odd if true
else       // x is even

// @caseCheck - Check uppercase/lowercase ANSI //
if (word[i] >= 'A' && word[i] <= 'Z')
else if (word[i] >= 'a' && word[i] <= 'z')
