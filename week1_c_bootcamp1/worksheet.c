#include <stdio.h>

int main(){
    int length;
    int breadth;
    int Area;
    printf("Enter length: ");
    scanf("%d", &length);
    printf("Enter breadth: ");
    scanf("%d", &breadth);
    
    Area = length*breadth;
    printf("Area %d\n", Area);

    return 0;
}