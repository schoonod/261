#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main(int argc, const char * argv[]){
    char cmd = ' ';
    DynArr* mainList = createDynArr(10);
    
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    
    do{
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
               );
        /* get input command (from the keyboard) */
        cmd = getchar();
        /* clear the trailing newline character */
        struct Task* newTask;
        struct Task* firstTask;
        
        int priority;
        FILE *file;
        char desc[TYPE_SIZE], filename[100], *nlptr;

        
        while (getchar() != '\n');
        
        switch (cmd){
            // Load to-do list
            case 'l':
                printf("Enter filename: ");

                if (fgets(filename, sizeof(filename), stdin) != NULL){
                    nlptr = strchr(filename, '\n');
                    if (nlptr)
                        *nlptr = '\0';
                }

                file = fopen(filename, "r");
                if (file == NULL) {
                    fprintf(stderr, "Cannot open %s\n", filename);
                    break;
                }
                
                loadList(mainList, file);
                /* close the file */
                fclose(file);
                printf("The list has been loaded from file successfully.\n\n");
                break;
                
            // Save the list to file
            case 's':
                if (sizeDynArr(mainList) > 0){

                    printf("Enter Filename: ");
                    if (fgets(filename, sizeof(filename), stdin) != NULL){
                        nlptr = strchr(filename, '\n');
                        if (nlptr)
                            *nlptr = '\0';
                    }
                    file = fopen(filename, "w");
                    if (file == NULL) {
                        fprintf(stderr, "File is null %s\n", filename);
                        break;
                    }

                    saveList(mainList, file);

                    fclose(file);
                    
                    printf("List saved.\n");
                }
                else
                    printf("No list to save.\n");
                
                break;

            // Add task
            case 'a':
                printf("Enter the task description: ");
                if (fgets(desc, sizeof(desc), stdin) != NULL)
                {
                    nlptr = strchr(desc, '\n');
                    if (nlptr)
                        *nlptr = '\0';
                }
                do {
                    printf("Please enter the task priority (0-999): ");
                    scanf("%d", &priority);
                } while (!(priority >= 0 && priority <= 999));
                
                while (getchar() != '\n');
                
                /* create task and add the task to the heap */
                newTask = createTask(priority, desc);
                addHeap(mainList, newTask, compare);
                printf("The task '%s' has been added to your to-do list.\n", desc);
                break;
                
            
            // Get first task
            case 'g':
                if (sizeDynArr(mainList) > 0){
                    firstTask = getMinHeap(mainList);
                    printf("Your first task is: %s\n", firstTask->description);
                }
                else
                    printf("There are no tasks.\n");
                
                break;
            
            // Remove first task
            case 'r':
                if (sizeDynArr(mainList) > 0){
                    firstTask = getMinHeap(mainList);
                    removeMinHeap(mainList, compare);
                    printf("'%s' removed.\n\n", firstTask->description);
                    free(firstTask);
                }
                else
                    printf("There are no tasks to remove.\n");
                
                break;
            
            // Print task list.
            case 'p':
                if (sizeDynArr(mainList) > 0){
                    printList(mainList);
                }
                else
                    printf("There are no tasks to print.\n");
                
                break;
            
            // Exit Program
            case 'e':
                break;
                
            default:
                printf("Enter a valid command.\n");
                break;
        }
    } while (cmd != 'e');
    /* delete the list */
    deleteDynArr(mainList);
    
    return 0;
}