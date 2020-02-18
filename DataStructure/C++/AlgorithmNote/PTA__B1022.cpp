#include <iostream>
using namespace std;

int main()
{
    int a, b, d, sum;
    int ans[31];
    cin >> a >> b >> d;
    sum = a + b;
    int num = 0;
    //进制转换
    do
    {
        ans[num++] = sum % d;
        sum /= d;
    } while (sum != 0);
    //从高位到低位输出
    for (int j = num - 1; j >= 0; j--) {
        cout << ans[j];
    }
    return 0;
}