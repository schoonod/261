/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
    // Sort the n students based on their score
    // Citation: The C Programming Language (Kernighan and Ritchie), pg. 55, shell sort
    int gap;
    int temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i-gap; j>=0 && students[j].score > students[j+gap].score; j-=gap) {
                temp = students[j].score;
                students[j].score = students[j+gap].score;
                students[j+gap].score = temp;
            }
        }
    }
    
}

void generate(struct student* students){
    
    for(int i = 0; i < 10; i++){
        
        int uniqueID = 0;
        
        students[i].id = rand()%10+1;
        students[i].score = rand()%(100)+1;
        
        while (uniqueID == 0 && i > 0){
            int reset = 0;
            for (int j = i-1; j >= 0; j--){
                if (students[i].id == students[j].id){
                    students[i].id = rand()%10+1;
                    reset = 1;
                }
            }
            if (reset == 0)
                uniqueID = 1;
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n * sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
    generate(students);

    /*Print the contents of the array of n students.*/
    for (int i = 0; i < 10; i++){
        printf("%d %d\n", students[i].id, students[i].score);
    }
    
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", students[i].id, students[i].score);
    
    return 0;
}
