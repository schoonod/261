/*
Table of Contents
Dynamic Array
	Bag
	Stack
	Deque
LinkedList
	Stack
	Queue
	Deque (doubly)
Sorting
  quickSort
  mergeSort
  shellSort
  bubbleSort

Search
	binary
MACROS
String Manipulation
  toUpper
  toLower
  oddEven
  caseCheck
*/

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// @DYNAMIC ARRAY --------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
struct DynArr {
	TYPE *data;		  // Pointer to the data array
	int size;		    // Number of elements in the array
	int capacity;		// Capacity of the array
};
//*******************************************************************
// Initialize (including allocation of data array) dynamic array DATA.
void initDynArr(struct DynArr *da, int capacity) {
	assert(capacity > 0);
	assert(da != 0);
	da->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(da->data != 0);
	da->size = 0;
	da->capacity = capacity;
}
//*******************************************************************
// Allocate and initialize DynArr.
DynArr* newDynArr(int capacity){
	assert(capacity > 0);
	DynArr *r = (DynArr *)malloc(sizeof(DynArr));
	assert(r != 0);
	initDynArr(r,capacity);
	return r;
}
//*******************************************************************
// Deallocate the data in DynArr.
void freeDynArr(struct DynArr *da) {
	if(da->data != 0) {
		free(da->data); 	  // Free the space on the heap
		da->data = 0;   	  // Make it point to null
	}
	da->size = 0;
	da->capacity = 0;
}
//*******************************************************************
// Deallocate data array and the dynamic array
void deleteDynArr(DynArr *da){
	freeDynArr(da);
	free(da);
}
//*******************************************************************
// Return the size of the Dynamic array (elements)
int sizeDynArr(struct DynArr *da) {
	assert(da != 0);
	return da->size;
}
//*******************************************************************
// ADD a value to the end of the array
void addVal(struct DynArr *v, TYPE val) {
	assert(da != 0);
	if(v->size >= v->capacity)
		_setCapDynArr(v, 2 * v->capacity);
	v->data[v->size] = val;
	v->size++;
}
//*******************************************************************
// RESIZE - Double the size of the array
void _setCapDynArr(struct DynArr *da, int newCap) {
	assert(da != 0);
	TYPE *temp = malloc(sizeof(TYPE) * newCap);
	for(int i = 0; i < da->size; i++){
		temp[i] = da->data[i];
	}
	free(da->data);
	da->capacity = newCap;
	da-> data = temp;
}
//*******************************************************************
// GET a value at a specified position in the array
TYPE getDynArr (struct DynArr * da, int position) {
	assert(da != 0);
  assert(da->size > 0);
	assert(da->size >= position);
  return da->data[position];
}
//*******************************************************************
// PUT a value at a specified position in the array
void putDynArr(struct DynArr * da, int position, TYPE value) {
			assert(da != 0);
	    assert(da->size > 0);
	    assert(pos < da->capacity);
	    da->data[pos] = val;
}
//*******************************************************************
// Swap two array positions
void swapDynArr (struct DynArr * da, int i, int j) {
	assert(da != 0);
	assert(da->size > 0);
	assert((i >= 0 && j >= 0) && (i < da->size && j < da->size));
	TYPE temp;
  temp = da->data[i];
  da->data[i] = da->data[j];
  da->data[j] = temp;
}
//*******************************************************************
// Removes the value held at a specific location and shifts remaining elements
void removeAtDynArr (struct DynArr * da, int index) {
	assert(da != 0);
	assert(da->size > 0);
	assert(index >=0 && index < da->size);
  da->data[index] = NULL;
  // move the remaining values back
	for(int i = index; i < da->size; i++) {
    da->data[i] = v->data[i+1];
  }
  da->size = da->size - 1;
}
//*******************************************************************
// @ORDEREDDynamicArray
// @setOperations

/*
Take, for example, set intersection. The intersection copies a value when it is
found in both collections. Notice that in this abstraction it is more convenient
to have the set operations create a new set, rather than modifying the arguments.
Union copies the smaller element when they are unequal, and when they are equal
copies only one value and advances both pointers (remember that in a set all
elements are unique, each value appears only once). The difference copies values
from the first collection when it is smaller than the current element in the
second, and ignores elements that are found in both collections. Finally there
is the subset test. Unlike the others this operation does not
produce a new set, but instead returns false if there are any values in the first
collection that are not found in the second. But this is the same as returning
false if the element from the left set is ever the smallest value (indicating
it is not found in the other set).
*/

// Intersect
void arraySetIntersect (struct dyArray *left, struct dyArray *right, struct dyArray *to) {
	int i = 0;
	int j = 0;
	while ((i < dyArraySize(left)) && (j < dyArraySize(right))) {
		if (LT(dyArrayGet(left, i), dyArrayGet(right, j))
			i++;
		else if (EQ(dyArrayGet(left, i), dyArrayGet(right, j))) {
			dyArrayAdd(to, dyArrayGet(left, i));
			i++; j++;
		}
		else
			j++;
	}
}

// Union

// Difference

// Subset

//------------------------------------------------------------------------------

// @BagDynamicArray

//------------------------------------------------------------------------------
// Returns T/F if dynArr contains/does not contain value e
int containsDynArr (struct DynArr * da, TYPE e) {
	assert(da != 0);
	assert(da->size > 0);
	for(int i=0; i <= da->size; i++){
   	 if(da->data[i] == e)
   		 return 1;
  }
  return 0;
}
//**************************************
void removeDynArr (struct DynArr * da, TYPE val) {
	assert(da != 0);
	assert(da->size > 0);
	for (int i = 0; i < da->size; i++) {
    if (da->data[i] == val){ 						/* found it */
    	//removeAtDynArr(da, i);
			v->data[i] = 0;
			v->size -= 1;
		}
  }
}
//**************************************
int sizeArray (struct arrayBagStack * b) {
  return b->count;
}
//**************************************
// @ORDEREDdBag
// Find the correct location to insert a value (binary search)
void orderedArrayAdd (struct dyArray *dy, TYPE newElement) {
	int index = binarySearch(dy->data, dy->size, newElement);
	dyArrayAddAt (dy, index, newElement);
}

void dyArrayAddAt (struct dyArray *dy, int index, TYPE newElement) {
	int i;
	assert(index > 0 && index <= dy->size);
	if (dy->size >= dy->capacity)
		_setCapacityDy++)Arr(dy, 2 * dy->capacity);
	for (i = index; i < size; i++)
		dy->data[index + 1] = dy->data[index];
	dy->data[index] = newElement;
	dy->size += 1
}
//------------------------------------------------------------------------------

// @StackDynamicArray

//------------------------------------------------------------------------------
// Determine if array is empty
int isEmptyDynArray (struct DynArr * da) {
	assert(v != 0);
	if(da->size == 0)
 	 return 1;
  else
 	 return 0;
}
//**************************************
// Add to top of array
void pushDynArray (struct DynArr * da, TYPE e) {
	assert(v != 0);
	if(v->size >= v->capacity){
		dynArrSetCapacity(v, 2 * v->capacity);
	}
	v->data[v->size] = val;
	v->size++;
}
//**************************************
// Remove from top of array
void popDynArray (struct DynArr * da) {
	assert(da != 0);
	assert(da->size > 0);
	da->data[v->size-1] = 0;
	// removeAtDynArr(da,da->size);
  da->size--;
}
//**************************************
// Return top of array
TYPE topDynArray (struct DynArr * da) {
	assert(da != 0);
  assert(da->size > 0);
	return getDynArr (da, (da->size - 1));
}
//------------------------------------------------------------------------------

// @DequeDynamicArray

//------------------------------------------------------------------------------
struct deque {
	TYPE * data;
 	int capacity;
 	int size;
 	int start;
};
//**************************************
void dequeInit (struct deque *d, int initCapacity) {
 	d->size = d->start = 0;
 	d->capacity = initCapacity; assert(initCapacity > 0);
 	d->data = (TYPE *) malloc(initCapacity * sizeof(TYPE));
 	assert(d->data != 0);
}
//**************************************
int dequeSize (struct deque *d) {
	return d->size;
}
//**************************************
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
//**************************************
void dequeAddFront (struct deque *d, TYPE newValue) {
	if (d->size >= d->capacity)
		_dequeSetCapacity(d, 2*d->capacity);

	if (start == 0){
		d->data[capacity - 1] = newValue;
		start = capacity - 1
	}
	else {
		d->data[start - 1] = newValue
		start--
	}
	size++;
}
//**************************************
void dequeAddBack (struct deque *d, TYPE newValue) {
	int index;
	if (d->size >= d->capacity)
		_dequeSetcapacity(d, 2* d->capacity);
	index = d->start + d->size);			// empty position after element at the back of the deque
		if (index >= d->capacity)
			index -= d->capacity;
	d->data[index] = newValue;
	d->size++;
}
//**************************************
TYPE dequeFront (struct deque *d) {
	if (size > 0)
		return d->data[start];
}
//**************************************
void dequeFree (struct deque *d) {
 	free(d->data);
 	d->size = 0;
 	d->capacity = 0;
}
//**************************************
TYPE dequeBack (struct deque *d) {
	int index = d->start + d->size -1;		// element at the back of the deque
	if (index > d->capacity)
		index -= d->capacity;
	return d->data[index];
}
//**************************************
void dequeRemoveFront (struct deque *d) {
	if (d->size > 0){
		d->start += 1
		d->size -= 1;
	}
}
//**************************************
void dequeRemoveBack (struct deque *d) {
	if (d->size > 0)
		d-size -= 1;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// @LINKED LIST ----------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Linked list struct
struct Link {
	TYPE val;
	struct Link *next;
}
//------------------------------------------------------------------------------

// @StackLinkedList

//------------------------------------------------------------------------------
struct ListStack {
	struct Link *firstLink;
}
//**************************************
struct listStackInit (ListStack s) {
	s->firstLink = 0;
}
//**************************************
void pushListStack(struct ListStack *s, TYPE d){
	struct Link *newLink = (struct Link *) malloc(sizseof(struct Link));		// allocate a new Link
	assert(newLink != 0);
	newLink->val = d;										// set newLink value
	newLink->next = s->firstLink;				// set newLink pointer to what firstLink was pointing to (next link or 0)
	s->firstLink = newLink;							// change newLink to point to  newLink
}
//**************************************
TYPE linkedListStackTop (struct linkedListStack *s) {
	if(s->firstLink != NULL)
		return s->firstLink->value;
	return NULL;
}
//**************************************
void linkedListStackPop (struct linkedListStack *s) {
	if(s->firstLink != NULL){
		struct link* temp = s->firstLink;		// create temporary link to point at what firstLink points to
		s->firstLink = temp->next;					// reassign firstLink to what firstLink was pointing to n
		free(temp);													// free the address that firstLink was pointing to
	}
}
//**************************************
void linkedListStackFree (struct linkedListStack *s) {
	while (!linkedListStackIsEmpty(s))
		linkedListStackPop(s);
}
//**************************************
int linkedListStackIsEmpty (struct linkedListStack *s) {

	if(s->firstLink != NULL)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

// @QueueLinkedList

//------------------------------------------------------------------------------

struct listQueue {
	struct Link *firstLink;							// Always points to sentinel
	struct Link *lastLink;
}
//*******************************************************************
void listQueueInit(struct listQueue *q) {
	struct Link *lnk = (struct Link *) malloc(sizeof(struct Link));
		/* this initial lnk is the sentinel link */
	assert(lnk != 0);
	lnk->next = 0;
	q->firstLink = q->lastLink = lnk;
}
//*******************************************************************
void addBacklistQueue(struct listQueue *q, TYPE e) {
	struct Link *lnk = (struct Link *) malloc(sizeof(struct Link));
	assert(lnk != 0);
	lnk->value = e;
	lnk->next = q->lastLink->next;			// or lnk->next = 0;
	q->lastLink->next = lnk;						// Point the lastLink to the new link (the new lastLink)
	q->lastlink = lnk;									// Reassign the lastLink pointer to the newLink
}
//*******************************************************************
TYPE listQueueFront (struct listQueue *q) {
	if(q->firstLink != NULL)
		return q->firstLink->value;

}
//*******************************************************************
void listQueueRemoveFront (struct listQueue *q) {
	if(q->firstLink != NULL){
		struct link* temp = q->firstLink;
		q->firstLink = temp->link;
		free(temp);
	}
//*******************************************************************
int listQueueIsEmpty (struct listQueue *q) {
	if(q->firstLink != NULL)
		return 1;
	return 0;
}
//------------------------------------------------------------------------------

// @DequeLinkedList(doubly)

//------------------------------------------------------------------------------
struct dLink {
	TYPE value;
	struct dlink * next;
	struct dlink * prev;
};
//*******************************************************************
struct linkedList {
	int size;
	struct dlink * frontSentinel;
	struct dlink * backSentinel;
};
//*******************************************************************
void LinkedListInit (struct linkedList *q) {
	q->frontSentinel = malloc(sizeof(struct dlink));
	assert(q->frontSentinel != 0);
	q->backSentinel = malloc(sizeof(struct dlink));
	assert(q->backSentinel);
	q->frontSentinel->next = q->backSentinel;
	q->backSentinel->prev = q->frontSentinell;
	q->frontSentinel->prev = 0;
	q->backSentinel->next = 0;
	q->size = 0;
}
//*******************************************************************
void linkedListFree (struct linkedList *q) {
	while (q->size > 0)
		linkedListRemoveFront(q);
	free (q->frontSentinel);
	free (q->backSentinel);
	q->frontSentinel = q->backSentinel = null;
}
//*******************************************************************
void LinkedListAddFront (struct linkedList *q, TYPE e) {
	_addBefore(q, q->frontSentinel_>next, e);
}
//*******************************************************************
void LinkedListAddback (struct linkedList *q, TYPE e) {
	_addBefore(q, q->backSentinel, e); }
//*******************************************************************
void linkedListRemoveFront (struct linkedList *q) {
	assert(! linkedListIsEmpty(q));
	_removeLink (q, q->frontSentinel->next);
}
//*******************************************************************
void LinkedListRemoveBack (struct linkedList *q) {
	assert(! linkedListIsEmpty(q));
	_removeLink (q, q->backSentinel->prev);
}
int LinkedListIsEmpty (struct linkedList *q) {
	return q->size == 0;
}
//------------------------------------------------------------------------------

// @IteratorLinkedList - Linked list traversing

//------------------------------------------------------------------------------
//**************************************
// Iterator struct
struct linkedListIter {
	struct dLink *cur;
	struct linkedList *lst
}
//**************************************
// Iterator init
void linkedListIteratorInit (struct linkedList *lst, struct linkedListIterator * itr) {
 itr->lst = lst;
 itr->cur = lst->frontSentinel; // **** lst->frontSentinel->next??
}
//**************************************
// Create an iterator
struct linkedListIter *createLLI(struct linkedList *lst){
	struct linkedListIter *newItr = malloc(sizeof(struct linkedListIter));
	assert(newItr !=0);
	initLinkedListIter(lst, newItr);
	return(newItr);
}
//**************************************
// Has next link to traverse? Set current link to next
int hasNextLinkedListIter(struct linkedListIter *itr){
	 if(itr->cur->next != itr->lst->backSentinel){
		 itr->cur = itr->cur->next;
		 return(1);
	 }
	 else
	 	return(0);
}
//**************************************
// GET next value; **current is now next after hasNext call,
// so current value is next value
TYPE nextLinkedListIter(struct linkedListIter *itr){
	return(itr->cur->value);	// ****Uncertain about this
}
//**************************************
// REMOVE last value returned by 'next'
void removeLinkedListIter(struct linkedListIter *itr) {
	struct dLink *tmp = itr->cur;
	itr->cur = itr->cur->prev;
	_removeLink(itr->lst, tmp);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// @SORTING --------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// @QuickSort

//------------------------------------------------------------------------------


void quickSort (double storage [ ], int n) {
	quickSortInternal (storage, 0, n-1); }

void quickSortInternal (double storage [ ], int low, int high) {
	if (low >= high) return; // base case
	int pivot = (low + high)/2; // one of many techniques
 	pivot = partition(storage, low, high, pivot);
 	quickSortInternal (storage, low, pivot-1); // first recursive call
 	quickSortInternal (storage, pivot+1, high); // second recursive call
 }
//------------------------------------------------------------------------------

// @MergeSort

//------------------------------------------------------------------------------
void mergeSort (double data [ ], int n) {
	double * temp = (double *) malloc (n * sizeof(double));
	assert (temp != 0); /* make sure allocation worked */
	mergeSortInternal (data, 0, n-1, temp);
	free (temp);
}
//*******************************************************************
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

//------------------------------------------------------------------------------

// @ShellSort

//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------

// @BubbleSort

//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------

// @SEARCH

//------------------------------------------------------------------------------

// @BinarySearch

//------------------------------------------------------------------------------
int binarySearch (TYPE * data, int size, TYPE testValue) { int low = 0;
	int high = size;
	int mid;
	while (low < high) {
		int mid = low + ((high - low) / 2);
		if (LT(data[mid], testValue))
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// MACROS ----------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//*******************************************************************
// Less Than
# ifndef LT
# define LT(A, B) ((A) < (B))		// if (LT(data[mid], testValue))
# endif
//*******************************************************************
// Equal To
# ifndef EQ
# define EQ(A, B) ((A) == (B)) // if (EQ(data[mid], testValue))
# endif
//*******************************************************************
// Symbolic Constant
# ifndef TYPE
# define TYPE int
# endif
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// STRING MANIPULATION ---------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// @toUpper - Convert ch to upper case, assuming it is in lower case currently /
char toUpperCase(char ch){
	return ch-'a'+'A';
}
//------------------------------------------------------------------------------
// @toLower - Converts ch to lower case, assuming it is in upper case currently/
char toLowerCase(char ch){
	return ch-'A'+'a';
}
//------------------------------------------------------------------------------
// @oddEven - Check if even or odd //
if (x % 2) // x is odd if true
else       // x is even
//------------------------------------------------------------------------------
// @caseCheck - Check uppercase/lowercase ANSI //
if (word[i] >= 'A' && word[i] <= 'Z')
else if (word[i] >= 'a' && word[i] <= 'z')
//-----------------------------------------------------------------------------
