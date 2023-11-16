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
FILE* file;
int Low_Step = 100000;
int High_Step = 0;
FITNESS_DATA Fitness[59];


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

FILE* Choice_A(char File[100], FILE *file){
    char* filename = File;
    file = fopen(filename, "r");
    if (file==NULL){
        printf("Error: Could not find or open the file.\n");
        perror("");
    }
    else{
        printf("File Succesfully loaded\n");
    }
    return file;
}

int Choice_B(FILE *file){
    int buffer_size = 200;
    char line[buffer_size];
    int counter = 0;

    while(fgets(line, buffer_size,file)!=NULL){
        counter++;
     }
    printf("Total Records: %d\n", counter);
}
void Choice_CD(char x, FILE *file){
    int buffer_size = 200;
    char line[buffer_size];
    int counter = 0;

  
    while(fgets(line, buffer_size,file)!=NULL){
        tokeniseRecord(line,",",date,time,steps);
        strcpy(Fitness[counter].date, date);
        strcpy(Fitness[counter].time, time);
        Fitness[counter].steps = atoi(steps);
        counter++;
    }
    if (x == 'C' || x == 'c'){
         for (int i = 0;i<counter;i++){
            if (Fitness[i].steps<Low_Step){
            Low_Step = Fitness[i].steps;
        }  
    }
    for (int i = 0; i<counter; i++){
        if (Fitness[i].steps == Low_Step){
            printf("Fewest Steps: %s %s\n", Fitness[i].date, Fitness[i].time);
        }
    }   
    }
    else if (x == 'D' || x == 'd'){
        for (int i = 0;i<counter;i++){
        if (Fitness[i].steps>High_Step){
            High_Step = Fitness[i].steps;
        }
    }
    for (int i = 0; i<counter;i++){
        if (Fitness[i].steps == High_Step){
            printf("Largest Steps: %s %s\n", Fitness[i].date, Fitness[i].time);
        }
    }
    }
}
int Choice_E(FILE *file){
    int buffer_size = 200;
    char line[buffer_size];
    int counter = 0;
    int High_Step = 0;
    int arr[200] = {};
    int sum = 0;
   
  
    while(fgets(line, 200,file)!=NULL){
        tokeniseRecord(line,",",date,time,steps);
        strcpy(Fitness[counter].date, date);
        strcpy(Fitness[counter].time, time);
        Fitness[counter].steps = atoi(steps);
        counter++;
    }
    for (int i = 0; i<counter; i++){
        arr[i] = Fitness[i].steps;
    }
    for (int i = 0; i<counter; i++){
        sum = sum + arr[i];   
    }
    printf("Mean Step Count: %d\n", (sum/counter));
}

int Choice_F(FILE *file){
    int buffer_size = 200;
    char line[buffer_size];
    int counter = 0;
    int High_Step = 0;
    int check = 0;
    int checking = 0;
    char *Start;
    char *SDate;
    char *EDate;
    char *End;

  
    while(fgets(line, 200,file)!=NULL){
        tokeniseRecord(line,",",date,time,steps);
        strcpy(Fitness[counter].date, date);
        strcpy(Fitness[counter].time, time);
        Fitness[counter].steps = atoi(steps);
        counter++;
    }
    for (int i = 0; i<counter; i++){
        if (Fitness[i].steps>500){
            check++;
            if (Fitness[i+1].steps<=500){
                if(check>checking){
                    checking = check;
                    Start = Fitness[(i-check)+1].time;
                    SDate = Fitness[(i-check)+1].date;
                    End = Fitness[i].time;
                    EDate = Fitness[i].date;
                    check = 0;
                }    

            }
        }

    }
    printf("Longest period start: %s %s\n", SDate,Start);
    printf("Longest period end: %s %s\n", EDate,End);    
}

int main(){
    bool test = true;
    //int x = 0;
    char choice;
    char filename[100];

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

        if (choice == 'A' || choice == 'a'){
            printf("Input file name: ");
            scanf(" %s", filename);
            file = Choice_A(filename, file);
            if (file == NULL){ 
                return 1;
            }
        }

        else if (choice == 'B' || choice == 'b'){
            Choice_B(file);    
        }

        else if (choice == 'C' || choice == 'c'){
            Choice_CD(choice, file);
        }
        else if (choice == 'D' || choice == 'd'){
            Choice_CD(choice, file);
        }

        else if (choice == 'E' || choice == 'e'){
            Choice_E(file);
        }
        else if (choice == 'F' || choice == 'f'){
            Choice_F(file);
        }

        else if (choice == 'Q' || choice == 'q'){
            break;
        }     
        rewind(file);   
    }
    return 0;   
}









