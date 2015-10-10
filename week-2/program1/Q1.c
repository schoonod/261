// Author: Dane Schoonover
// Date Created: 10/9/2015
// Last Modification Date: 0/9/2015
// File name: Q0.c
// Overview:
//    This program dynamically allocates memory for a class of students, and creates
//    random, unique IDs and scores for the students.
// Input:
//    This program has no input.
// Output:
//    The output will be the unique IDs and scores associated with each studen, as
//    well as the max, min, and average scores for the students.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
    // Allocate memory for ten students
    struct student *students = malloc(10 * sizeof(struct student));
    // Return the pointer
    return students;
}

void generate(struct student* students){
    // Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100
    for(int i = 0; i < 10; i++){

        // UniqueID is false (0) until comparison is made to determine if unique
        int uniqueID = 0;

        // Assign an id to the student
        students[i].id = rand()%10+1;

        // Assign a score to the student
        students[i].score = rand()%(100)+1;

        // Check if assigned id is unique. While the id is not unique, and this is not the first id:
        while (uniqueID == 0 && i > 0){

            // Flag to tell us the id is unique. If a match is found while comparing student id's, then the flag is changed
            // to 'true', uniqueID remains false, the while loop continues, and comparisons are made until a unique id
            // is found
            int reset = 0;

            // Loop thru students with existing assigned id's, starting before current student
            for (int j = i-1; j >= 0; j--){

                // If the current student's id is equal to a previous student id
                if (students[i].id == students[j].id){

                    // Assign a new id to the current student
                    students[i].id = rand()%10+1;
                    // Flag while loop to reset and compare new ID against other IDs again
                    reset = 1;
                }
            }
            if (reset == 0)
                uniqueID = 1;
        }
    }
}


void output(struct student* students){

    /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    for (int i = 0; i < 10; i++)
        printf("%d %d\n", students[i].id, students[i].score);
}

void summary(struct student* students){

    /*Compute and print the minimum, maximum and average scores of the ten students*/

    int min = 100;      // min score value
    int max = 0;        // max score value
    int sum = 0;        // sum of all scores for average calculation
    int avg = 0;

    for (int i = 0; i < 10; i++){
        if (students[i].score < min)
            min = students[i].score;
        if (students[i].score > max)
            max = students[i].score;
        sum += students[i].score;
    }

    avg = sum/10;

    printf("Min is: %d\nMax is: %d\nAverage is: %d\n", min, max, avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if (stud != 0)
        free(stud);
}

int main(){
    struct student* stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
