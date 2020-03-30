//思路类似PTA__A1093
#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    int leftMax[100010], rightMin[100010],num[100010],ans[100010];
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> num[i];
    leftMax[0] = 0;
    rightMin[n - 1] = 0x3fffffff;

    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], num[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        rightMin[i] = min(rightMin[i + 1], num[i + 1]);

    for (int i = 0; i < n;i++) {
        if(num[i] > leftMax[i] && num[i] < rightMin[i])
            ans[count++] = num[i];
    }
    cout << count << endl;
    for (int i = 0; i < count; i++) {
        cout << ans[i];
        if(i < count - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}