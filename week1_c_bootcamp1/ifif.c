#include <stdio.h>

int main(){
    int mark;

    printf("Enter marks: ");
    scanf("%d", &mark);

    if (mark > 60 && mark < 100){
        printf("Approved\n");
    
    }
    else if (mark < 60 && mark > 0){
        printf("not approved\n");
    }
    else {
        printf("Enter a valid number between 0 to 100\n");
        
    }

    return 0;
}