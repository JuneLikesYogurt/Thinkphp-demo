#include<iostream>
using namespace std;

int  main() {
    int n;
    cin >> n;

    int count = 0;
    int num[100010] = {0};
    for (int i = 1; i <= n;i++) {
        int temp = 0,x = i;
        while(x > 0) {
            temp =  x % 10;
            if(temp == 1)
                count++;
            x = (x - temp) / 10;
        }
    }
    cout << count << endl;

    return 0;
}