#include <stdio.h>

int main(){
    char* filename = "square.dat";
    FILE *file = fopen(filename, "w");

    int n;

    printf("Enter: ");
    scanf("%d", &n);

    for (int i = 1; i<=n; i++){
        fprintf(file, "%d\n", (i*i));


    }
    fclose(file);
    return 0;

}