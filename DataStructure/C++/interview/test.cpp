#include<iostream>
using namespace std;

// int count(int res, int path,int m,int n,int flag) {
//     if(path < m) {
//         count(res, path++, m, n, flag[][]);
//     }
// }

// int solution(int m,int n) {
//     int res = 0;
//     int a[3][3];
//     for (int i = 0; i < 3;i++) {
//         for (int j = 0; j < 3;j++) {
//             int path = 1;
        
//         }
//     }
// }

int main() {
    int n;
    cin >> n;

    //第一題
    // int sum = 0,index = 1,indexCount = 1;
    // for(int i = 0;i < n; i++) {
    //     if(indexCount <= 0) {
    //         index++;
    //         indexCount = index;
    //     }
    //     sum += index;
    //     indexCount--;
    // }
    // cout << sum;

    //第二題 
    for (int i = 10; i < 10000001; i++) {
        int res = 1, num = i;
        while (num > 0)
        {
            int temp = num % 10;
            res *= temp;
            num = (num - temp) / 10;
        }
        if(res == n){
            cout << i << endl;
            break;
        }
            
    }
    cout << -1;
    
    //第三題
    // solution(m, n);

    return 0;
}