#include <stdio.h>

int calc(float one, float two, char x[1]){
    if (x=="+"){
        return one+two;
    }
    else if (x=="*"){
        printf("%f", (one*two));
    }

    else if (x=="-"){
        printf("%f", (one-two));
    }
    else if (x=="/"){
        printf("%f", (one/two));
    

    
    }
    return 0;
}

int main(){
    int o;
    int t;
    char *x[1];

    printf("Enter a first number: ");
    scanf("%d", &o);
    printf("Enter a second number: ");
    scanf("%d", &t);
    printf("Enter a arithmetic operator: ");
    scanf("%s*", &**x);

    printf("%d\n", calc(o,t,*x));


}