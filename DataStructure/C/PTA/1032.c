#include<stdio.h>
#define NUM 100001

int main()
{
    int x, y;
    int num,score;
    int sum[NUM] = {0};
    scanf("%d", &x);
    y = x;
    while (y)
    {
        scanf("%d %d", &num, &score);
        sum[num] += score;
        y--;
    }

    int i, MaxNum = 0;
    for (i = 1; i <= x; i++) //从编号1开始
    {
        if (sum[i] > sum[MaxNum])
        {
            MaxNum = i;
        }
    }

    printf("%d %d", MaxNum, sum[MaxNum]);

    return 0;
}
