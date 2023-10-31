#include <stdio.h>

int main(){
    int i=0;
    int arr[10];
    int tot = 0;
    for (i=0; i<10; i++){
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
        tot += arr[i];

        

        
    }

    int mean = tot/10;
    printf("%d", mean);

    return 0;

}