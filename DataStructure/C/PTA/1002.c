#include<stdio.h>
#define NUM 100

int printCN(int x) {
    int num[NUM];
    int i, j,count;
    int y = x;
    while(y) {  //计算位数
        y /= 10;
        count++;
    }
    for (i = count-1; i >= 0; i--)    //正序存放
    {
        num[i] = x % 10;
        x = x / 10;
    }
    for (j = 0; j < count;j++) {
        switch(num[j]) {
            case 1:
                printf("yi");
                break;
            case 2:
                printf("er");
                break;
            case 3:
                printf("san");
                break;
            case 4:
                printf("si");
                break;
            case 5:
                printf("wu");
                break;
            case 6:
                printf("liu");
                break;
            case 7:
                printf("qi");
                break;
            case 8:
                printf("ba");
                break;
            case 9:
                printf("jiu");
                break;
            case 0:
                printf("ling");
                break;
            default:
                return 0;
                break;
        }
        if(j != (count-1))
            printf(" ");
    }
    return 0;
}
int main() {
    char str[100];
    int i,temp,sum = 0;
    scanf("%s", str);
    for (i = 0; str[i] != '\0';i++) {
        temp = str[i] - '0';
        sum += temp;
    }
    printCN(sum);
    return 0;
}
