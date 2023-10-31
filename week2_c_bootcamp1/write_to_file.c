#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    int num_lines;
    int total = 0;
    
    printf("How many numbers;");
    scanf("%d",&num_lines);
    printf("Type in %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        total += number;
        fprintf(file, "%d\n", number);
    }
    float mean = total/num_lines;
    
    printf("Mean = %f\n", mean);
    fprintf(file, "Mean = %f\n", mean);



    fclose(file);
    return 0;
}