/*

****Use '@thingYouAreLookingFor' to jump to what you need

Table of Contents
Dynamic Array
	Bag
	Stack
	Deque
	Iterator
LinkedList
	Stack
	Queue
	Doubly
		BagDoublyLinkedList
		DequeDoublyLinkedList
		IteratorDoublyLinkedList
Binary Search Tree
	Bag
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
# ifndef TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// @DYNAMIC ARRAY --------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// The Dynamic Array
struct DynArr {
	TYPE *data;		  	// Pointer to the data array
	int size;		    // Number of elements in the array
	int capacity;		// Capacity of the array
};
//**************************************
// Initialize (including allocation of data array) dynamic array DATA.
void initDynArr(struct DynArr *dyAr, int capacity) {
	assert(dyAr != NULL);
	assert(capacity > 0);
	dyAr->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(dyAr->data != NULL);
	dyAr->size = 0;
	dyAr->capacity = capacity;
}
//**************************************
// Allocate and initialize DynArr
struct DynArr* createDynArr(int capacity){
	assert(capacity > 0);
	struct DynArr *r = (DynArr *)malloc(sizeof(DynArr));
	assert(r != 0);
	initDynArr(r,capacity);
	return r;
}
//**************************************
// Deallocate the data in DynArr
void freeDynArrData(struct DynArr *dyAr){
	if(dyAr->data != NULL) {
		free(dyAr->data); 	  // Free the space on the heap
		dyAr->data = 0;   	  // Make it point to null; as convention?
	}
	dyAr->size = 0;
	dyAr->capacity = 0;
}
//**************************************
// Deallocate data array and the dynamic array
void freeDynArr(struct DynArr *dyAr){
	freeDynArrData(dyAr);
	free(dyAr);
}
//**************************************
// Return the size of the Dynamic array (elements)
// O(1)
int sizeDynArr(struct DynArr *dyAr) {
	assert(dyAr != NULL);
	return dyAr->size;
}
//**************************************
// RESIZE - Double the size of the array
// O(n)
void setCapDynArr(struct DynArr *dyAr, int newCap) {
	assert(dyAr != NULL);
	TYPE *temp = malloc(sizeof(TYPE) * newCap);
	for(int i = 0; i < dyAr->size; i++){
		temp[i] = dyAr->data[i];
	}
	free(dyAr->data);
	dyAr->capacity = newCap;
	dyAr->data = temp;
}
//**************************************
// ADD a value to the end of the array
// O(1)+
void dyArrayAdd(struct DynArr *dyAr, TYPE val) {
	assert(dyAr != 0);
	if(dyAr->size >= dyAr->capacity)
		setCapDynArr(dyAr, 2 * dyAr->capacity);
	dyAr->data[dyAr->size] = val;
	dyAr->size++;
}
//**************************************
// GET a value at a specified position in the array
// O(1)
TYPE getDynArr (struct DynArr * dyAr, int position) {
	assert(dyAr != NULL);
  	assert(dyAr->size > 0);
	assert(dyAr->size >= position);
  	return dyAr->data[position];
}
//**************************************
// PUT a value at a specified position in the array
// O(1)
void putDynArr(struct DynArr * dyAr, int position, TYPE value) {
	assert(dyAr != NULL);
    assert(dyAr->size > 0);	// Why is this necessary?
    assert(position < dyAr->size);
    dyAr->data[position] = value;
}
//**************************************
// Swap two array positions
// O(1)
void swapDynArr (struct DynArr * dyAr, int i, int j) {
	assert(dyAr != NULL);
	assert(dyAr->size > 0);
	assert((i >= 0 && j >= 0) && (i < dyAr->size && j < dyAr->size));
	TYPE temp;
  	temp = dyAr->data[i];
  	dyAr->data[i] = dyAr->data[j];
  	dyAr->data[j] = temp;
}
//**************************************
// Removes the value held at a specific location and shifts remaining elements
// O(n)
void removeAtDynArr (struct DynArr * dyAr, int index) {
	assert(dyAr != NULL);
	assert(dyAr->size > 0);
	assert(index >=0 && index < dyAr->size);
  	// dyAr->data[index] = NULL; --> unnecessary step?
  	// move the remaining values back
	for(int i = index; i < dyAr->size; i++) {
    	dyAr->data[i] = dyAr->data[i+1];
  	}
  	dyAr->size--;
}
//*******************************************************************
// @ORDEREDDynamicArray
//*******************************************************************
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
void arraySetIntersect (struct dynArr *left, struct dynArr *right, struct dynArr *to) {
	int i = 0;
	int j = 0;
	while ((i < dynArrSize(left)) && (j < dynArrSize(right))) {
		if (EQ(dynArrGet(left, i), dynArrGet(right, j))) {
			dynArrAdd(to, dynArrGet(left, i));
			i++; j++;
		else if (LT(dynArrGet(left, i), dynArrGet(right, j)) {
			i++;
		}
		else
			j++;
	}
}

// Union

// Difference

// Subset

//------------------------------------------------------------------------------
/*
		@BagDynamicArray
			uses:
				initDynArr
				createDynArr
*/
//------------------------------------------------------------------------------
// Returns T/F if bag contains/does not contain value e
// O(n)
int containsDynArr (struct DynArr * dyAr, TYPE e) {
	assert(dyAr != NULL);
	assert(dyAr->size > 0);
	for(int i=0; i <= dyAr->size; i++){
   	 if(dyAr->data[i] == e)
   		 return 1;
  }
  return 0;
}
//**************************************
// Remove a value from bag
// O(n)
void removeDynArr (struct DynArr * dyAr, TYPE val) {
	assert(dyAr != NULL);
	assert(dyAr->size > 0);
	for (int i = 0; i < dyAr->size; i++) {
    if (dyAr->data[i] == val){ 						/* found it */
		dyAr->data[i] = 0;
		dyAr->size -= 1;
	}
  }
}
//**************************************
// Return size of the bag
// O(1)
int sizeArray (struct arrayBagStack * b) {
  return b->size;
}
//**************************************
// @ORDEREDdBag
//**************************************
//**************************************
// Returns the index of the testValue or if it does not exist, the index of where it should go
// O(log n)
int dynArrBinarySearch (struct dynArr * dyAr, TYPE testValue) {
   return _binarySearch (dyAr->data, dyAr->size, testValue);
}
//**************************************
// Adds a value at given index
// O(n)
void dynArrAddAt (struct dynArr *dy, int index, TYPE newElement) {
	int i;
	assert(index > 0 && index <= dy->size);
	if (dy->size >= dy->capacity)
		_setCapacityDyArr(dy, 2 * dy->capacity);
	// Shift elements right
	for (i = index; i < dy->size; i++)
		dy->data[index + 1] = dy->data[index];
	dy->data[index] = newElement;
	dy->size += 1
}
//**************************************
// Insert a value at the correct ordered location
// O(n)
void orderedArrayAdd (struct dynArr *dy, TYPE newElement) {
	int index = binarySearch(dy->data, dy->size, newElement);	// returns the location to enter a value
	dynArrAddAt(dy, index, newElement);
}
//**************************************
// Contains
// O(log n)
int orderedArrayContains (struct dynArr *dyAr, TYPE testElement) {
	assert(dyAr != null)
	int index = _binarySearch(dyAr->data, dyAr->size, newElement);
	return(dyAr->data[index] == testElement);
}
//**************************************
// Remove
// O(n) 
void orderedArrayRemove (struct dynArr *dyAr, TYPE testElement) {
	assert(dyAr != null)
	int index = _binarySearch(dyAr->data, dyAr->size, newElement);
 	removeAtDynArr(dyAr, index);
}
//------------------------------------------------------------------------------
/*
		@StackDynamicArray
			uses:
				initDynArr
				createDynArr
*/
//------------------------------------------------------------------------------
// Determine if array is empty
int isEmptyDynArray (struct DynArr * dyAr) {
	assert(dyAr != NULL);
	if(dyAr->size == 0)
 	 return 1;
  else
 	 return 0;
}
//**************************************
// Add to top of array
// O(1)+, O(n) with resize
void pushDynArray (struct DynArr * dyAr, TYPE e) {
	assert(dyAr != NULL);
	if(dyAr->size >= dyAr->capacity){
		dynArrSetCapacity(dyAr, 2 * dyAr->capacity);
	}
	dyAr->data[dyAr->size] = val;
	dyAr->size++;
}
//**************************************
// Remove from top of array
// O(1)
void popDynArray (struct DynArr * dyAr) {
	assert(dyAr != NULL);
	assert(dyAr->size > 0);
	dyAr->data[dyAr->size-1] = 0;
	// removeAtDynArr(dyAr,dyAr->size);
  dyAr->size--;
}
//**************************************
// Return top of array
// O(1)
TYPE topDynArray (struct DynArr * dyAr) {
	assert(dyAr != NULL);
  assert(dyAr->size > 0);
	return getDynArr (dyAr, (dyAr->size - 1));
}
//------------------------------------------------------------------------------
/*
		@DequeDynamicArray
			uses:
				createDynArr
*/
//------------------------------------------------------------------------------
// Deque structure
struct deque {
	TYPE * data;
 	int capacity;
 	int size;
 	int start;		// needed due to wrapping
};
//**************************************
// Initialize
void dequeInit (struct deque *dyAr, int initCapacity) {
 	dyAr->size = dyAr->start = 0;
 	dyAr->capacity = initCapacity; 
 	assert(initCapacity > 0);
 	dyAr->data = (TYPE *) malloc(sizeof(TYPE) * initCapacity);
 	assert(dyAr->data != NULL);
}
//**************************************
// Set new capacity
// O(n)
void _dequeSetCapacity (struct deque *d, int newCap) {	
	/* Create a new underlying array*/
	TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
	assert(newData != 0);
	
	// Copy elements to new array; Reorganzies array to start from index = 0 (i)
	int j = d->start;
	for(int i = 0; i <  d->size; i++){
		newData[i] = d->data[j];
		j++;
		if(j >= d->capacity)
			j = 0;
	}
	
	/* Delete the oldunderlying array*/
	free(d->data);
	/* update capacity and size and data*/
	d->data = newData;
	d->capacity = newCap;
	d->start = 0;
}
//**************************************
// Return deque size
// O(n)
int dequeSize (struct deque *dyAr) {
	return dyAr->size;
}
//**************************************
// Add to the front of the deque
// O(1)+
void dequeAddFront (struct deque *dyAr, TYPE newValue) {
	if (dyAr->size >= dyAr->capacity)
		_dequeSetCapacity(dyAr, 2 * dyAr->capacity);

	// if the array starts after index 0
	if {
		dyAr->data[start - 1] = newValue
		start--
	}
	// else if the start is at index 0, add to the back of the array
	else if (dyAr->start == 0 && dyAr->size > 0){
		dyAr->data[capacity - 1] = newValue;
		start = capacity - 1
	}

	// else this is the first entry
	else if (dyAr->start == 0 && dyAr->size == 0)
		dyAr->data[start] = newValue;

	size++;
}
//**************************************
// Add to the bacK of the deque
// O(1)+
void dequeAddBack (struct deque *dyAr, TYPE newValue) {
	int index;
	// If it's full, increase capacity
	if (dyAr->size >= dyAr->capacity)
		_dequeSetcapacity(dyAr, 2 * dyAr->capacity);
	// The logical index of the empty position at the back of the deque
	index = dyAr->start + dyAr->size;			
		if (index >= dyAr->capacity)
			// Wrap the index to the front if the logical index is greater than capacity
			index -= dyAr->capacity;
	dyAr->data[index] = newValue;
	dyAr->size++;
}
//**************************************
// Return the front of the deque
// O(1)
TYPE dequeFront (struct deque *dyAr) {
	assert(dryAr->size > 0)
	return dyAr->data[start];
}
//**************************************
// Free the deque data and reset properties
// O(1)
void dequeFree (struct deque *dyAr) {
 	if(dyAr->data != 0)
 		free(dyAr->data);
 	dyAr->size = 0;
 	dyAr->capacity = 0;
 	dyAr->start = 0;
}
//**************************************
// Return the back of the deque
// O(1)
TYPE dequeBack (struct deque *dyAr) {
	// element at the back of the deque
	int index = dyAr->start + dyAr->size -1;		
	if (index > dyAr->capacity)
		// Wrap the index
		index -= dyAr->capacity;
	return dyAr->data[index];
}
//**************************************
// Remove the front of the deque
// O(1)
void dequeRemoveFront (struct deque *dyAr) {
	Assert(dyAr->size > 0);
	dyAr->start += 1;
	dyAr->size -= 1;
}
//**************************************
// Remove the back of the deque
// O(1)
void dequeRemoveBack (struct deque *dyAr) {
	assert(dyAr->size > 0);
	dyAr-size -= 1;
}
//------------------------------------------------------------------------------

// @IteratorDynamicArray

//------------------------------------------------------------------------------
// Iterator Structure
struct dynArrayIterator {
   struct dynArray * dyAr;
   int currentIndex;
};
//**************************************
// Initialize
void dynArrayIteratorInit (struct dynArray *dyAr, struct dynArrayIterator *itr) {
	itr->dynArray = dyAr;
	itr->currentIndex = 0;
}
//**************************************
// Create the iterator
struct DynArrIter *createDynArrIter(struct DynArr *dyAr){
	struct DynArrIter *newItr = malloc(sizeof(struct DynArrIter));
	assert(newItr != 0);
	initDynArrIter(dyAr, newItr);
	return(newItr);
}
//**************************************
// If iterator has next, sets iterator index to next index
// O(1)
int dynArrayIteratorHasNext (struct dynArrayIterator *itr) {
	if(itr->dyAr->data[currentIndex]+1) != dyAr->capacity){
			itr->dyAr->data[currentIndex]++;
			return(1);
		}
		else
		 	return(0);
}
//**************************************
// Returns the value of the next element
// O(1)
TYPE dynArrayIteratorNext (struct dynArrayIterator *itr) {
	return(itr->dyAr->data[currentIndex]);
}
//**************************************
// Removes the element at the current index
// O(n)
void dynArrayIteratorRemove (struct dynArrayIterator *itr) {
	removeAtDynArr(itr->dyAr, itr->currentIndex);
	itr->currentIndex--;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// @LINKED LIST ----------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Standard link struct
struct Link {
	TYPE val;
	struct Link *next;
}
//------------------------------------------------------------------------------

// @StackLinkedList

//------------------------------------------------------------------------------
// The Stack List
struct listStack {
	struct Link *firstLink;
}
//**************************************
// Initialize
struct listStackInit (listStack s) {
	s->firstLink = 0;
}
//**************************************
// Create a stackLL
struct listStack *createLinkedList(){
	struct listStack *newList = malloc(sizeof(struct listStack));
	_initList(newList);
	return(newList);
}
//**************************************
// Pushes a link onto the stack
void pushStackLL(struct listStack *s, TYPE val){
	struct Link *newLink = (struct Link *) malloc(sizseof(struct Link));		// allocate a new Link
	assert(newLink != NULL);
	newLink->val = val;							// set newLink value
	newLink->next = s->firstLink;				// set newLink->next to what firstLink is pointing to (next link in the stack or 0)
	s->firstLink = newLink;						// change firstLink to point to newLink
}
//**************************************
// Return stack top value
TYPE linkedListStackTop (struct linkedListStack *s) {
	assert(!isEmptyLinkedList(l));
  	return l->firstLink->val;

}
//**************************************
// Removes stop of stack
void popStackLL (struct linkedListStack *s) {
	assert(!isEmptyLinkedList(l));
	struct link* temp = s->firstLink;		// create temporary link to point at what firstLink points to
	s->firstLink = temp->next;				// reassign firstLink to what firstLink was pointing to n
	free(temp);								// free the address that firstLink was pointing to
	}
}
//**************************************
// Frees all links but keeps firstLink, so list still exists and remains intialized
// O(n)
void freeStackLL (struct linkedListStack *s) {
	while (!linkedListStackIsEmpty(s))
		popStackLL(s);
}
//**************************************
// Deletes the stackLL
// O(n)
void deleteStackLL(struct LinkedList *s){
	_freeLinkedList(l);
	free(l);
}
//**************************************
// Is empty?
// O(1)
int isEmptyStackLL (struct linkedListStack *s) {
	return (s->firstLink != NULL);
}
//------------------------------------------------------------------------------

// @QueueLinkedList

//------------------------------------------------------------------------------
struct listQueue {
	struct Link *firstLink;							// Always points to sentinel
	struct Link *lastLink;
}
//**************************************
void listQueueInit(struct listQueue *lst) {
	struct Link *lnk = (struct Link *) malloc(sizeof(struct Link));
		/* this initial lnk is the sentinel link */
	assert(lnk != NULL);
	lnk->next = 0;
	lst->firstLink = lst->lastLink = lnk;
}
//**************************************
struct listQueue *createLinkedList(){
	struct listQueue *newList = malloc(sizeof(struct listQueue));
	_initList(newList);
	return(newList);
}
//**************************************
void addBacklistQueue(struct listQueue *lst, TYPE e) {
	struct Link *lnk = (struct Link *) malloc(sizeof(struct Link));
	assert(lnk != NULL);
	lnk->value = e;
	lnk->next = lst->lastLink->next;			// or lnk->next = 0;
	lst->lastLink->next = lnk;						// Point the lastLink to the new link (the new lastLink)
	lst->lastlink = lnk;									// Reassign the lastLink pointer to the newLink
}
//**************************************
TYPE listQueueFront (struct listQueue *lst) {
	if(lst->firstLink != NULL)
		return lst->firstLink->value;

}
//**************************************
void listQueueRemoveFront (struct listQueue *lst) {
	if(lst->firstLink != NULL){
		struct link* temp = lst->firstLink;
		lst->firstLink = temp->link;
		free(temp);
	}
//**************************************
int listQueueIsEmpty (struct listQueue *lst) {
	if(lst->firstLink != NULL)
		return 1;
	return 0;
}
//------------------------------------------------------------------------------

// @DoublyLinkedList

//------------------------------------------------------------------------------
// Doubly link struct
struct dLink {
	TYPE value;
	struct dLink * next;
	struct dLink * prev;
};
//**************************************
// Doubly list struct
struct linkedList {
	int size;
	struct dLink * firstLink;
	struct dLink * lastLink;
};
//**************************************
struct linkedList *createLinkedList(){
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}
//**************************************
void linkedListInit (struct linkedList *lst) {
	assert(lst != NULL);
	lst->firstLink = malloc(sizeof(struct dlink));
	assert(lst->firstLink != NULL);
	lst->lastLink = malloc(sizeof(struct dlink));
	assert(lst->lastLink);
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLinkl;
	lst->firstLink->prev = 0;
	lst->lastLink->next = 0;
	lst->size = 0;
}
//------------------------------------------------------------------------------
/*
		@BagDoublyLinkedList
			uses:
 				DoublyLinkedList
					dLink (constructor)
					linkedList (constructor)
					initList
 					createLinkedList
*/
//------------------------------------------------------------------------------
//**************************************
void addList(struct linkedList *lst, TYPE v){
	assert(lst != NULL);
	_addBefore(lst, lst->lastLink, v);
}
//**************************************
void removeList (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	assert(lst->size > 0);
	struct DLink *temp;								// create link 'walker'
	temp = lst->firstLink->next;
	while(temp->next != lst->lastLink){
		if(temp->value == e)
			_removeLink(lst, temp);
	}
}
//**************************************
// Determine if value exists in the linkedList
int linkedListContains (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	assert(lst->size > 0);
	struct dLink *temp;								// create link 'iterator'
	temp = lst->firstLink->next;
	while(temp->next != lst->lastLink){
			if(temp->value == e)
				return 1;
		temp = temp->next;
	}
	return 0;
}
//------------------------------------------------------------------------------
/*
		@DequeuDoublyLinkedList
			uses:
				DoublyLinkedList
						dLink (constructor)
						linkedList (constructor)
						initList
	 					createLinkedList
*/
//------------------------------------------------------------------------------
void LinkedListAddback (struct linkedList *lst, TYPE e) {
	_addBefore(lst, lst->lastLink, e);
}
//**************************************
void linkedListRemove (struct linkedList *lst, TYPE e) {
	assert(lst->firstLink->next != NULL);
	struct dLink *temp;
	temp = lst->firstLink->next;
	while(temp != lst->lastLink){
		if(temp->value == e){
			_removeLink(lst, temp);
			return;
		}
		temp = temp->next;
		///// *** free temp?
	}
}
//**************************************
void _addBefore (struct linkedList *lst, struct dlink *lnk, TYPE e) {
	assert(lst != NULL);
	assert(lnk != NULL);
		if (lst->firstLink != lst->lastLink){
			struct dLink *newLink = malloc(sizeof(struct dLink));
			assert(lst->firstLink != NULL);
			newLink->value = e;
			// the link to the left of newLink, has a new next of newLink
			lnk->prev->next = newLink;
			// newLink’s prev is the link it comes after
			newLink->prev = lnk->prev;
			// the link to the right of newLink has a new prev of newLink
			lnk->prev = newLink;
			// newLink’s next is the link it comes before
			newLink->next = lnk;
	}
	st->size++;
}
//**************************************
void _removeLink (struct linkedList *lst, struct dlink *lnk) {
	assert(lst != NULL);
	assert(lnk != NULL);
	if (lst->firstLink != lst->lastLink){
		// the link to the prev of lnk has a new prev of lnk’s prev
		lnk->next->prev = lnk->prev;
		// the link to the left of lnk has a new next of lnk’s next
		lnk->prev->next = lnk->next;
		free(lnk);
	}
	lst->size--;
}
//**************************************
void linkedListFree (struct linkedList *lst) {
	while (lst->size > 0)
		linkedListRemoveFront(lst);
	free (lst->firstLink);
	free (lst->lastLink);
	lst->firstLink = lst->lastLink = null;
}
//**************************************
void LinkedListAddFront (struct linkedList *lst, TYPE e) {
	_addBefore(lst, lst->firstLink->next, e);
}
//**************************************
void LinkedListAddback (struct linkedList *lst, TYPE e) {
	_addBefore(lst, lst->lastLink, e);
}
//**************************************
void linkedListRemoveFront (struct linkedList *lst) {
	assert(lst != NULL);
	assert(lst->size > 0);
	_removeLink(lst, lst->firstLink->next);
}
//**************************************
void removeBackList(struct linkedList *lst){
	assert(lst != NULL);
	assert(lst->size > 0);
	_removeLink(lst, lst->lastLink->prev);
}
//**************************************
int LinkedListIsEmpty (struct linkedList *lst) {
	assert(lst != NULL);
	return lst->size == 0;
}
//**************************************
TYPE frontList (struct linkedList *lst) {
	assert(lst != NULL);
	assert(lst->size > 0);
	return lst->firstLink->next->value;
}
//**************************************
TYPE backList(struct linkedList *lst){
	assert(lst != NULL);
	assert(lst->size > 0);
	return lst->lastLink->prev->value;	return(1);
}
//**************************************
void _printList(struct linkedList* lst){
	assert(lst != NULL);
	struct DLink *temp;								// create link 'iterator'
	temp = lst->firstLink->next;
	while(temp->next != lst->lastLink){
		printf("%i \n", temp->value);
		temp = temp->next;
	}
}
//------------------------------------------------------------------------------

// DequeCircularlyDoublyLinkedList

//------------------------------------------------------------------------------
struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};

/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);

//**************************************
// Initialize
void _initCirListDeque (struct cirListDeque *q) {
	assert(q != NULL)
	q->Sentinel = (struct DLink *)malloc(sizeof(struct DLink));
	assert(q->Sentinel != 0);
	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;
	q->size = 0;
	q->Sentinel->value = 0;
}
//**************************************
// Create a new circular list deque
struct cirListDeque *createCirListDeque(){
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}
//**************************************
// Create a new link
struct DLink * _createLink (TYPE val){
	struct DLink* newLink = (struct DLink *)(malloc(sizeof(struct DLink)));
	assert(newLink != 0);
	newLink->value = val;
	return(newLink);
}
//**************************************
// Add a new link with value v, after a the link
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v){
	assert(q != NULL);
	assert(lnk != NULL);
	struct DLink *newLink = _createLink(v);
	newLink->next = lnk->next;
	newLink->prev = lnk;
	lnk->next = newLink;
	newLink->next->prev = newLink;
	q->size++;
	return;
}
//**************************************
// Add a link to the back of the Circular deque
void addBackCirListDeque (struct cirListDeque *q, TYPE val) {
	assert(q != 0);
     _addLinkAfter(q, q->Sentinel->prev, val);
}
//**************************************
// Add a link to the front of the Circular deque
void addFrontCirListDeque(struct cirListDeque *q, TYPE val){
     assert(q != 0);
     _addLinkAfter(q, q->Sentinel, val);
}
//**************************************
// Return the value of the link in the front of the Circular deuque
TYPE frontCirListDeque(struct cirListDeque *q) {
	assert(q != 0);
	assert(q->size > 0);
    return(q->Sentinel->next->value);
}
//**************************************
// Return the value of the link in the back of the Circular deuque
TYPE backCirListDeque(struct cirListDeque *q){
	assert(q != 0);
	assert(q->size > 0);
    return(q->Sentinel->prev->value);
}
//**************************************
// Remove the specified link (lnk)
void _removeLink(struct cirListDeque *q, struct DLink *lnk){
 	assert(q != 0);
 	assert(q->size > 0);
	lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;
    free(lnk);
    q->size--;
}
//**************************************
// Removes the first link
void removeFrontCirListDeque (struct cirListDeque *q) {
     _removeLink(q, q->Sentinel->next);

}
//**************************************
// Removes the last link
void removeBackCirListDeque(struct cirListDeque *q){
     _removeLink(q, q->Sentinel->prev);
}
//**************************************
// De-allocates all of the links
void freeCirListDeque(struct cirListDeque *q){
	while (q->size > 0){
        _removeLink(q, q->Sentinel->next); 
    }	
}
//**************************************
// Checks if empty
int isEmptyCirListDeque(struct cirListDeque *q) {
	assert(q != NULL);
	return q->size == 0;
}
//**************************************
// Prints all values (if int)
void printCirListDeque(struct cirListDeque *q){

	assert(q != 0);
    struct DLink *temp = q->Sentinel->next;
 		while (temp != q->Sentinel){
          printf("%f \n", temp->value);
          temp = temp->next;
    }
}
//**************************************
// Reverse the deque
void reverseCirListDeque(struct cirListDeque *q){
	assert(q != 0);
	assert(q->size > 0);
	struct DLink * temp = q->Sentinel->next;
	struct DLink * temp2;
	q->Sentinel->next = q->Sentinel->prev;
    q->Sentinel->prev = temp;
	while (temp != q->Sentinel){
		temp2 = temp->prev;
		temp->prev = temp->next;
		temp->next = temp2;
		temp = temp2;
	}
}
//------------------------------------------------------------------------------

// @IteratorDoublyLinkedList - Linked list traversing

//------------------------------------------------------------------------------
// Link
struct dLink {
	TYPE value;
	struct dLink * next;
	struct dLink * prev;
};
//**************************************
// Doubly list struct
struct linkedList {
 struct dLink * firstLink;
 struct dLink * lastLink;
 int size;
};
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
	itr->cur = lst->firstLink; // **** lst->firstLink->next
}
//**************************************
// Create an iterator
struct linkedListIter createLLI(struct linkedList *lst){
	struct linkedListIter *newItr = malloc(sizeof(struct linkedListIter));
	assert(newItr !=0 );
	initLinkedListIter(lst, newItr);
	return(newItr);
}
//**************************************
// Has next link to traverse? Set current link to next
// O(1)
int hasNextLinkedListIter(struct linkedListIter *itr){
	 if(itr->cur->next != itr->lst->lastLink){
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
	return(itr->cur->value);
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
// @BINARY SEARCH TREE ---------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// @BagBinarySearchTree

//------------------------------------------------------------------------------
// Node struct
struct Node {
   TYPE value;
   struct Node * left;
   struct Node * right;
};
//**************************************
// Binary Search Tree struct
struct BinarySearchTree {
   struct Node *root;
   int size;
};
//**************************************
// Initialize
void initBST(struct BinarySearchTree *tree) { 
	tree->size = 0; 
	tree->root = 0: 
}
//**************************************
// Add a new value to the tree
void addBST(struct BinarySearchTree *tree, TYPE newValue) {
	tree->root = _nodeAddBST(tree->root, newValue);  
	tree->size++; 
}
//**************************************
// Return tree sizse
int sizeBST (struct binarySearchTree *tree) { 
	return tree->size; 
}
//**************************************
// Adds a node to the BST
struct Node * _nodeAddBST (struct Node *current, TYPE newValue) {
	if (current == 0) {
		newNode = malloc (sizeof(struct Node));
		assert(newNode !=0);
		newNode->value = value;
		newNode->left = newNode->right = 0;
			return newNode;
	}	
	else if (value < current ->value) {
		current->left = _nodeAddBST(current->left, value);
	}

	else {
		current->right = _nodeAddBST(current->right,value);
	}

	return current;
}
//**************************************
// Returns T/F if a node exists
struct Node *current = tree->root;
	while (current !=0) {
		if (current->value == value) {
	}
		else if (value < current->value) {
			current = current->left;
	}
		else {
			current = current->right;
	}
}
//**************************************
// Returns leftmost child of a node
TYPE _leftMostChild (struct Node * current) {		
	assert(current != null);
	if(current->left != NULL) {
			return _leftMostChild(current->left);
		return current->value;
	}
}
//**************************************
// Removes a node
void removeBST (struct binarySearchTree *tree, TYPE d) {
   if (containsBST(tree, d) {
      tree->root = _nodeRemoveBST(tree->root, d);
      tree->size--;
   }
}
//**************************************
// Removes a leftmost child, while also setting the current->left to current->left->right (replaces leftmost child with the child's right)
struct node * _removeLeftmostChild (struct Node *current) {
	assert(current !=0);	
	if (current->left == 0) {
		struct Node *temp = current
	    free(current);
		return temp->right?;
	}
	else {
		current->left = _removeLeftmostChild(current->left);
	}
}
// Notes: A companion routine (removeLeftmost) is a function to return a tree with the leftmost child removed. Again, traverse the tree until 
// the leftmost child is found.  When found, return the right child (which could possibly be null) to become the new current->left of the replaced node. 
// Otherwise make a recursive call and set the left child to the value returned by the recursive call (the right child of leftmost child), 
// and return the current Node.
//**************************************
// Returns the newly replaced node
struct Node *  _nodeRemoveBST (struct Node * current, TYPE d) {
	if (current-> value == value) {
		***decrease size
		if (current->right == 0) {
			struct Node *temp = current->left;
			free(current);
			return temp;
		}
	} 
		else {
			current->value = _leftMostChild(current->right);
			current->right = _removeLeftmostChild(current->right);
		} 
	}
	
	else if (value < current->value) {
		current->left = _nodeRemoveBST(current->left, value);
	} 

	else {
		current-> right = _nodeRemoveBST(current->right, value);
	}
	
	return current;
}
//**************************************
/*  nodeRemoveBST concept
	Node remove is a function that removes the desired node by traversing the tree until found, and replaces
		that Node with the leftmost child of the right child, of that node. This leftmost child is used because it is
		bigger than all left descendants of the replaced node, yet smaller than all right descendants of the replaced
		node. It also means that no other rearranging must take place once this value takes the place of the replaced node.

Node remove (Node start, E testValue)
 if start->value is the value we seek (== testValue)
 	decrease the value of dataSize (b/c we are removing it)
 	if right child is null (meaning that there is no right subtree that we have to worry about, only a left tree)
 		return left child (this will replace the value being removed)
	 otherwise
	 	replace value of node with leftmost child of right child
	 	right child = removeLeftmost(right child)
	 		--> this will free the leftmost child's previous memory location
	 		--> and return the the right child (if any) of that leftmost child to become the new left value of the replaced node's right value
 otherwise if testValue is smaller than start.value, go down left subtree
 	left child = nodeRemoveBST(left child, testValue)	
 		--> this makes left child = the value returned by nodeRemoveBST, which is the leftmost child
 otherwise, testValue is greater, so go down right tree
 	set right child to remove(right child, testValue)	 
 		--> right child becomes the leftmost child
 return current node
 	--> current node is the new node that replaced the removed one
 	--> it's former spot that it moved from has also been freed
 	--> and 
*/
//------------------------------------------------------------------------------

// @AVL Tree

//------------------------------------------------------------------------------
// AVL node Struct
struct AVLnode {
	TYPE value;
	struct AVLnode *left;
	struct AVLnode *right;
	int height;
};
//**************************************
// Height-balanced binary search tree
struct AVLTree {
	struct AVLNode *root;
	int count;
}
//**************************************
// Initialize
void initAVL(struct AVLTree *tree){
	tree->root = 0;
	tree->count = 0;
}
//**************************************
// Create the tree
struct AVLTree *tree(){
	struct AVL *tree = (struct AVLTree *)malloc(sizeof(struct AVLTree));
	assert(tree != 0);
	initAVL(tree);
	return tree;
}
//**************************************
// Return height of node
int _h(struct AVLnode * current) {
	if (current == 0) 
		return -1;  
	return 
		current->height;
}

//**************************************
// Set height of node, assuming height of child nodes is known
void _setHeight (struct AVLnode * current) {
	int lch = h(current->left);
	int rch = h(current->right);
	if (lch < rch) current->height = 1 + rch;
	else current->height = 1 + lch;
}
 //**************************************
// Add a node then balance balance the tree
struct AVLnode * _AVLnodeAdd (struct AVLnode* current, TYPE newValue) {
	struct AVLnode * newnode;
	if (current == 0) {
		newnode = (struct AVLnode *) malloc(sizeof(struct AVLnode));
		assert(newnode != 0);
		newnode->value = newValue;
		newnode->left = newnode->right = 0;
		return newnode; 
	} 
	else if (LT(newValue, current->value))
		current->left = AVLnodeAdd(current->left, newValue);
	else 
		current->right = AVLnodeAdd(current->right, newValue);

	return balance(current);
}
//**************************************
// Balance Factor
int _bf (struct AVLnode * current) { 
	return h(current->right) - h(current->left); 
}
// Balance Functino
 struct AVLnode * _balance (struct AVLnode * current) {
      int cbf = bf(current);
      if (cbf < -1) {
         if (bf(current->left) > 0) // double rotation
            current->left = rotateLeft(current->left);
         return rotateRight(current); // single rotation
      } else if (cbf > 1) {
         if (bf(current->right) < 0)
            current->right = rotateRight(current->right);
         return rotateLeft(current);
      }
      setHeight(current);
      return current;
   }
//**************************************
// Rotate the current tree left
struct AVLnode * _rotateLeft (struct AVLnode * current) {
	struct AVLnode *pivot = current->right;
	current->right = pivot->left;
	pivot->left = current;
	current = pivot;
	_setHeight(current->left);
	_setHeight(current);
	return current;
}
//**************************************
// Rotate the current tree right
struct AVLnode * _rotateRight (struct AVLnode * current) {
	struct AVLnode *pivot = current->left;
	current->left = pivot -> right;
	pivot->right = current;
	current = pivot;
	_setHeight(current->right);
	_setHeight(current);
	return current;
}
//**************************************
// Remove a value from the tree
void removeAVLTree(struct AVLTree *tree, TYPE val) {
   if (containsAVLTree(tree, val)) {
      tree->root = _removeNode(tree->root, val);
      tree->cnt--;
   }
}

TYPE _leftMost(struct AVLNode *cur) {
   while(cur->left != 0) {
      cur = cur->left;
   }
    return cur->val;
}

struct AVLNode *_removeLeftmost(struct AVLNode *cur) {
	struct AVLNode *temp;

   if(cur->left != 0)
   {
      cur->left = _removeLeftmost(cur->left);
      return _balance(cur);
   }

   temp = cur->rght;
   free(cur);
   return temp;
}

struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val) {
	assert(cur != NULL);

	if(cur->value == val){
		cur->value = _leftMost(cur->right);
		_removeLeftmost(cur->right);
	} else if (val > cur->value) {
		_removeNode(cur->right, val);
	} else if (val < cur->value){
		_removeNode(cur->left, val);
	}
return  _balance(cur);

//**************************************

//**************************************
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
	assert (temp != NULL); /* make sure allocation worked */
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
void bubbleSort (double data[], int n) {
  for (int i = n-1; i > 0; i--){
    for (int j = 0; j < i; j++){
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
int _binarySearch (TYPE * data, int size, TYPE testValue) { int low = 0;
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
// Pointer to void
#ifndef __FILE_H
#define __FILE_H
# define TYPE void *
// user defined compare function
// 0 if l = r
// -1 if l < r
// 1 if l > r
// int compare (TYPE left, TYPE right);
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
