/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

int getLength(char *str){
    // Citation: http://stackoverflow.com/questions/8831323/find-length-of-string-in-c-without-using-strlen
    int length = 0;
    while(str[length]!='\0'){
        length++;
    }
    
    return length;
}

void sticky(char* word, int strLength){

    // Convert to sticky caps
    for (int i = 0; i < strLength; i++){
        // If letter index is odd, change it to lowercase
        if ((i%2 != 0) && word[i] >= 'A' && word[i] <= 'Z')
            word[i] = toLowerCase(word[i]);
        
        // Else it's even and change to uppercase
        else if ((i%2 == 0) && word[i] >= 'a' && word[i] <= 'z')
            word[i] = toUpperCase(word[i]);
    }
}


int main(){
    /*Read word from the keyboard using scanf*/
    char str[20];
    printf("Enter a legal string\n");
    scanf("%19s", str);
    
    // Get length of string
    int strLength = getLength(str);
    printf("String length is: %d\n", strLength);

    /*Call sticky*/
    sticky(str, strLength);
    
    /*Print the new word*/
    printf("%s\n", str);
    
    return 0;
}
