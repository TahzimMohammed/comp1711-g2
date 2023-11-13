#include <stdio.h>

int sum (int a, int b)
{
    int answer;
    answer = a + b;
    return answer;
}

int main ()
{
    int y = 2;
    int z = sum(10,7); // calling the function

    printf("The sum of 5 and %d is %d\n", y, z);
    
}