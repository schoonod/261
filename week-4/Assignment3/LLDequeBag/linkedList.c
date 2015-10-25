// Author: Dane Schoonover
// Date Created: 10/23/2015
// Last Modification Date: 10/24/2015
#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// BAG
/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	assert(lst != NULL);
	lst->firstLink = malloc(sizeof(struct DLink));
	assert(lst->firstLink != 0);
	lst->lastLink = malloc(sizeof(struct DLink));
	assert(lst->lastLink);
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
	lst->firstLink->prev = 0;
	lst->lastLink->next = 0;
	lst->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList(){
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	assert(lst != NULL);
	assert(l != 0);
	if (lst->firstLink != lst->lastLink){
		struct DLink *newLink = malloc(sizeof(struct DLink));
		assert(lst->firstLink != 0);
		newLink->value = v;
		// the link to the left of newLink, has a new next of newLink
		l->prev->next = newLink;
		// newLink’s previous is the link it comes after
		newLink->prev = l->prev;
		// the link to the right of newLink has a new previous of newLink
		l->prev = newLink;
		// newLink’s next is the link it comes before
		newLink->next = l;
	}
	lst->size++;
}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e){
	_addLinkBefore(lst, lst->firstLink->next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	_addLinkBefore(lst, lst->lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	assert(lst != NULL);
	assert(lst->size > 0);
	return lst->firstLink->next->value;
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst){
	assert(lst != NULL);
	assert(lst->size > 0);
	return lst->lastLink->prev->value;	return(1);
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
	assert(lst != NULL);
	assert(l != 0);
	if (lst->firstLink != lst->lastLink){
		// the link to the prev of lnk has a new previous of lnk’s previous
		l->next->prev = l->prev;
		// the link to the left of lnk has a new next of lnk’s next
		l->prev->next = l->next;
		free(l);
	}
	lst->size--;
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst){
	assert(lst != NULL);
	assert(lst->size > 0);
	_removeLink(lst, lst->firstLink->next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst){
	assert(lst != NULL);
	assert(lst->size > 0);
	_removeLink(lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
	assert(lst != NULL);
	return lst->size == 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst){
	assert(lst != NULL);
	struct DLink *temp;								// create link 'walker'
	temp = lst->firstLink->next;
	while(temp->next != lst->lastLink){
		printf("%i \n", temp->value);
		temp = temp->next;
	}
}

/* 
	Add an item to the bag
	param: 	lst	pointer to the bag
	param: 	v value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v){
	assert(lst != NULL);
	_addLinkBefore(lst, lst->lastLink, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	assert(lst != NULL);
	assert(lst->size > 0);
	struct DLink *temp;								// create link 'walker'
	temp = lst->firstLink->next;
	while(temp->next != lst->lastLink){
		if(temp->value == e)
			return 1;
		temp = temp->next;
	}
	return 0;}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
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



