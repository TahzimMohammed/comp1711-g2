#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"
#include <stdbool.h>

// Struct moved to header file

// Define any additional variables here
char date[11];
char time[6];
char steps[20];

// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

 }




// Complete the main function

int Choice_A(char File[100]){
    char* filename = File;
    FILE*input = fopen(filename, "r");
    if (input==NULL){
        printf("Error: Could not find or open the file.\n");
        perror("");
        return 1;
    }
    else{
        printf("File Succesfully loaded\n");
    }
}

int Choice_B(){
    int buffer_size = 200;
    char line[buffer_size];
    int counter = 0;

    FILE*input = fopen("FitnessData_2023.csv", "r");
    if (input==NULL){
        perror("");
        return 1;
    }
    

    
    
    printf("Total Records: %d\n", counter);

}

int Choice_C(){
    FITNESS_DATA Fitness[59];
    int buffer_size = 200;
    char line[buffer_size];
    int counter = 0;
    char Fewest[100];

    FILE*input = fopen("FitnessData_2023.csv", "r");
    if (input==NULL){
        perror("");
        return 1;
    }
  
    while(fgets(line, 200,input)!=NULL){
        tokeniseRecord(line,",",date,time,steps);
        strcpy(Fitness[counter].date, date);
        strcpy(Fitness[counter].time, time);
        Fitness[counter].steps = atoi(steps);
    }
    

}


int main(){
    bool test = true;
    //int x = 0;
    char choice;
    char input[100];
    FITNESS_DATA Fitness[59];

    while (test != false){
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");

        printf("Enter Choice: ");
        scanf(" %c", &choice);

        if (choice == 'A'){
            printf("Input file name: ");
            scanf(" %s", input);
            Choice_A(input);
        }

        else if (choice == 'B'){
            Choice_B();    
        }

        else if (choice =='C'){
            printf("Third Option\n");
        }

        else if (choice == 'Q'){
            break;
        }
        
    }
    return 0;
   
}









