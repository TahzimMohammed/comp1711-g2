#include <stdio.h>
int x;
int y;

void transpose(int a[][3]){
    int Tarray[3][2];
    printf("Before\n");
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 3; ++j){
            printf("%d ", a[i][j]);
            
        }   
     printf("\n"); // start new line of output 
    }
    
    printf("After\n");



}


int main(){
    int array[2][3] = {{1,2,3}, {4,5,6}};
    transpose(array);

}