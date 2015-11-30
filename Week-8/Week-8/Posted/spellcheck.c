/*
 Dane Schoonover
 261-400
 Programming Assignment #6
 Hash Implementation of a Concordance
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers seperated by periods, spaces, or newlines.
 
 when there are no more words in the input file this function will return NULL.
 
 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

/*
 Load the contents of file into hashmap ht
 */
void loadDictionary(FILE* file, struct hashMap* ht);

int main (int argc, const char * argv[]) {
  clock_t timer;
  struct hashMap* hashTable;
  int tableSize = 1000;
  timer = clock();
  initMap(hashTable,tableSize);
  
  FILE* dictionary;
  
  loadDictionary(dictionary,hashTable);
  timer = clock() - timer;
	printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
  
  char* word = (char*)malloc(256*sizeof(char));
  int quit=0;
  while(!quit){
    printf("Enter a word: ");
    scanf("%s",word);

    if (atMap(hashTable, word) == NULL)
        // If the word is not in the dictionary
        printf("%s is not a word.\n", word);
    else
        // Word is in the dictionary
        printf("%s is spelled correctly.\n", word);
    
    /* Don't remove this. It is used for grading*/
    if(strcmp(word,"quit")==0)
      quit=!quit;
  }
  free(word);
     
  return 0;
}

void loadDictionary(FILE* file, struct hashMap* ht){
    while (1){
        char* word = getWord(file);
        if (word == NULL)
            break;
        else{
            insertMap(ht, word, 0);
            free(word);
            continue;
        }
    }
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   (character == 39)) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
