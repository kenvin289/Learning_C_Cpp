#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct svien {
    int masv;
} hihi;

int main()
{
    // int a, b;
    // scanf("%d %d", &a, &b);

    // printf("hello khoa \n");
    // printf("a = %d, b = %d \n", a, b);

    int a;
    a = sqrt(16);
    printf("sqrt(16) = %d \n", a);

    for(int i = 0; i < 5; i++)
        printf("%d \n", i);
    
    int i = 10;
    while(i != 0){
        printf("hello \n");
        i--;
    }
    
    return 1;
}