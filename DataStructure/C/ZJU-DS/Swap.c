#include<stdio.h>

void swap (int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    int m[2] = {1,5};
    // scanf("%d %d", &a, &b);
    // printf("%d %d\n", a,b);
    // swap(&a,&b);
    // printf("swap:%d %d\n", a,b);

    swap(&m[0],&m[1]);
    printf("%d %d\n", m[0],m[1]);

    return 0;
}