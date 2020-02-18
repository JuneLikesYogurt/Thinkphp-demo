#include <stdio.h>
//最大子列和-在线处理
int Count(int a[], int n)
{
	int i;
	int ThisSum = 0, MaxSum = 0;
	for (i = 0; i < n; i++)
	{
		ThisSum += a[i];
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
		}
		else if (ThisSum <= 0)
		{
			ThisSum = 0;
		}
	}
	return MaxSum;
	//T(N) = O(N)
}

int main()
{
	int n, a[100000];
	int MaxSum;
	if(scanf("%d", &n)){};//防止scanf返回值warning
	//输入数据
	int i;
	for (i = 0; i < n; i++)
	{
		if(scanf("%d", &a[i])){};
	}
	MaxSum = Count(a, n);
	printf("%d", MaxSum);
	return 0;
}
