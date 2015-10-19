/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"
#include "assert.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
    assert(s != 0);
    DynArr *v = newDynArr(10);
	char temp = nextChar(s);
	
	do{
		printf("test\n");
		printf("%c\n", temp);
		if (temp == '(' || temp == '{' || temp == '['){
			printf("%s\n", "test2");
			if (temp == '('){
				pushDynArr(v, ')');
				printf("%s\n", "test3");
			}

			else if (temp == '{')
				pushDynArr(v, '}');
			else if (temp == '[')
				pushDynArr(v, ']');
		}
		
		else if (temp == ')' || temp == '}' || temp == ']'){
			printf("%s\n", "test4");
			if (sizeDynArr(v) > 0){
				if(temp == topDynArr(v))
					popDynArr(v);
			}
			else
				return 0;
		}
		
		printf("%s\n", "test6");
		temp = nextChar(s);

	} while (temp != '\0');
	
	printf("%s\n", "test7");
	if (sizeDynArr(v) > 0)
		return 0;
	else
		return 1;
}

int main(int argc, char* argv[]){
	
	char* s = argv[1];
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

