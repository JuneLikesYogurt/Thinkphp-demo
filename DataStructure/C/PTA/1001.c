#include<stdio.h>

int main() {
    int x;
    int count = 0;
    scanf("%d", &x);
    while(x != 1) {
        if((x % 2) != 0)    //为奇
            x = x * 3 + 1;
        x = x / 2;
        count++;
    }
    printf("%d", count);
    return 0;
}
