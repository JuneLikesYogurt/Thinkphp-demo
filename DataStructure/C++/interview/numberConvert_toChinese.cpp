#include <iostream>
#include <string.h>
using namespace std;


int convert (int number) {
    int temp = 0,i = 0,j = 0;
    int num;
    while(num) {
        temp = num % 10;
        res[i++] = a[temp];
        res[i++] = b[j++];
        num = (num - temp) / 10;
    }
    for (int x = i; x >= 0;x--) {
        cout << res[x];
    }
}

int main() {
    string number;
    cin >> number;

    int num = number;

    cout << num << end;
    // int number;
    // cin >> number;
    // convert(number);

    return 0;
}