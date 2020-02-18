#include <stdio.h>
//最大子列和-在线处理
int Count(int a[], int n)
{
	int i;
	int ThisSum = 0, MaxSum = 0;

	int tempFirst = 0;
	int first = 0, last = n - 1; //如果存在负数，需要输出子列首、尾的情况
	int flag = 0;	//子列中是否含0

	for (i = 0; i < n; i++)
	{
		ThisSum += a[i];
		if(a[i] == 0) 
		{
			flag = 1;
		}
		//thiSum>maxSum,此时first last为最大子列和的首部和尾部
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			first = tempFirst;
			last = i;
		}
		if (ThisSum < 0)
		//！！！，<=0会忽略最大子列和前面有一串0的情况
		{
			//ThisSum<0 重置first
			tempFirst = i + 1;
			ThisSum = 0;
		}
	}

	//输出
	if (MaxSum <= 0)
	{
		//当子列中只有0和负数
		/*有0和负数单独列出的原因：
			最后一个子列为负数时，输出“0 0 x”。而只有0和负数时，要求输出“0 0 0”
		*/
		if (flag == 1) {
		printf("%d %d %d", 0, 0, 0);
		}
		//当子列中只有负数
		else {
		printf("%d %d %d", 0, a[0], a[n - 1]);
		}
	}
	else
	{	
		printf("%d %d %d", MaxSum, a[first], a[last]);
	}
	return 0;
	//T(N) = O(N)
}

int main()
{
	int n, a[10000];
	if (scanf("%d", &n)){}; //防止scanf返回值warning

	//输入数据
	int i;
	for (i = 0; i < n; i++)
	{
		if (scanf("%d", &a[i])){};
	}
	Count(a, n);
	return 0;
}
