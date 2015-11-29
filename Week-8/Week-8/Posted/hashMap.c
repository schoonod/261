#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str){
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += str[i];
    return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str){
    int i;
    int r = 0;
    for (i = 0; str[i] != '\0'; i++)
        r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
    return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize){
    int index;
    if(ht == NULL)
        return;
    ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
    ht->tableSize = tableSize;
    ht->count = 0;
    for(index = 0; index < tableSize; index++)
        ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
    assert(tableSize > 0);
    hashMap *ht;
    ht = malloc(sizeof(hashMap));
    assert(ht != 0);
    _initMap(ht, tableSize);
    return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht){
    hashLink *current;
    hashLink *next;
    
    // Visit each bucket header
    for (int i = 0; i < ht->tableSize; i++) {
        current = ht->table[i];
        
        // Free existing links hanging from bucket until NULL reached
        while (current != NULL) {
            next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
    }
    
    free(ht->table);
    ht->tableSize = 0;
    ht->count = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
    assert(ht!= 0);
    /* Free all memory used by the buckets */
    _freeMap(ht);
    /* free the hashMap struct */
    free(ht);
}

/*
 Resizes the hash table to be the size newTableSize
 Companion to insertMap. insertMap calls resize if necessary, and
 _setTableSize calls insertMap to rehash after a resize
 */
void _setTableSize(struct hashMap * ht, int newTableSize){
    // Create table for the old data memory location
    hashLink **temp = ht->table;
    _initMap(ht, newTableSize);
    
    // Visit each bucket header
    for (int i = 0; i < ht->tableSize; i++){
        // Copy the header
        hashLink *current = ht->table[i];
        hashLink *next = NULL;
        
        // Copy the bucket at the current header
        while (current != NULL){
            insertMap(ht, current->key, current->value);
            next = current->next;
            current = next;
        }
    }
    // Remove the old data memory location
    free(temp);
    
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v){
    int index;
    
    // Check hashing function to determine index
    if (HASHING_FUNCTION == 1)
        index = stringHash1(k) % ht->tableSize;
    else if (HASHING_FUNCTION == 2)
        index = stringHash2(k) % ht->tableSize;
    
    // If the hash is negative, make it positive
    if (index < 0)
        index = index + ht->tableSize;
    
    // Check contains
    if (containsKey(ht, k))
        removeKey(ht, k);
    
    // Allocate and init new link
    hashLink *newLink = malloc(sizeof(struct hashLink));
    assert(newLink != NULL);
    newLink->key = k;
    newLink->value = v;
    newLink->next = 0;
    
    // Add link to 'bottom'(end) of bucket
    if (ht->table[index] != NULL){
        // Create walker
        hashLink *temp = ht->table[index];
        while (temp->next != NULL)
            temp = temp->next;
        
        // Temp->next is currently the end of the line
        temp->next = newLink;
    }
    
    // Bucket is empty, add in newLink
    else
        ht->table[index] = newLink;
    
    ht->count++;
    
    // Resize when appropriate
    if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
        _setTableSize(ht, ht->tableSize * 2);
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k){
    int index;
    
    // Check hashing function to determine index
    if (HASHING_FUNCTION == 1)
        index = stringHash1(k) % ht->tableSize;
    else if (HASHING_FUNCTION == 2)
        index = stringHash2(k) % ht->tableSize;
    
    // If negative, make positive
    if (index < 0)
        index = index + ht->tableSize;
    
    // Create walker
    hashLink* walker = ht->table[index];
    
    while (walker != NULL){
        // Compare the keys
        if (strcmp(walker->key, k) == 0)
            // return the address
            return (&(walker->value));
        else
            walker = walker->next;
    }
    
    // Else return false
    return NULL;
    
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k) {
    int hashIndex;
    
    // Check hashing function to determine index
    if (HASHING_FUNCTION == 1)
        hashIndex = stringHash1(k) % ht->tableSize;
    else if (HASHING_FUNCTION == 2)
        hashIndex = stringHash2(k) % ht->tableSize;
    
    // If negative, make positive
    if (hashIndex < 0)
        hashIndex = hashIndex + ht->tableSize;
    
    hashLink* walker = ht->table[hashIndex];
    
    // Compare the keys
    while (walker != NULL){
        if (strcmp(walker->key, k) == 0)
            // Return true
            return 99;
        else
            walker = walker->next;
    }
    return 0;
    
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k){
    int hashIndex;
    
    if (HASHING_FUNCTION == 1)
        hashIndex = stringHash1(k) % ht->tableSize;
    else if (HASHING_FUNCTION == 2)
        hashIndex = stringHash2(k) % ht->tableSize;
    
    if (hashIndex < 0)
        hashIndex = hashIndex + ht->tableSize;
    
    hashLink *walker = ht->table[hashIndex];
    hashLink *previous = NULL;
    
    if (walker == NULL)
        // Table is empty, key DNE
        return;
    
    // Traverse bucket
    while (strcmp(walker->key, k)!= 0){
        previous = walker;
        walker = walker->next;
        
        if (walker == NULL)
            // Key was not found
            return;
    }
    
    // Key was found, remove key
    if (previous != NULL)
        previous->next = walker->next;
    // This was the only key in the bucket, thus bucket is now empty
    else
        ht->table[hashIndex] = NULL;
    
    free(walker);
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht){
    return ht->count;
    
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht){
    return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht){
    
    int buckets = 0;
    
    // Traverse the headers
    for (int i = 0; i < ht->tableSize; i++){
        if (ht->table[i] == NULL)
            buckets += 1;
    }
    return buckets;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht){  
    return ((float)ht->count / (float)ht->tableSize);
}

void printMap (struct hashMap * ht)
{
    int i;
    struct hashLink *temp;	
    for(i = 0;i < capacity(ht); i++){
        temp = ht->table[i];
        if(temp != 0) {		
            printf("\nBucket Index %d -> ", i);		
        }
        while(temp != 0){			
            printf("Key:%s|", temp->key);
            printValue(temp->value);
            printf(" -> ");
            temp=temp->next;			
        }		
    }
}


