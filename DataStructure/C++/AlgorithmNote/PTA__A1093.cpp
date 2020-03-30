//思路类似PTA__A1101
#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    string str;
    int leftNum[100000] = {0};
    int ans = 0, rightNum = 0;

    cin >> str;
    int len = str.length();

    for (int i = 0; i < len; i++) {
        if(i > 0)
            leftNum[i] = leftNum[i - 1];    //继承上一位
        if(str[i] == 'P')
            leftNum[i]++;
    }
    for (int i = len - 1; i >= 0;i--) {
        if(str[i] == 'T')
            rightNum++;
        else if(str[i] == 'A'){
            ans = (ans + leftNum[i] * rightNum) % MOD;
        }
    }

    cout << ans;
    return 0;
}