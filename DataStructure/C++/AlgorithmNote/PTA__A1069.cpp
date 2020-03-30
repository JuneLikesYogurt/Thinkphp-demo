#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b) { //递减排列，sort默认递增排列
    return a > b;
}

void toArray(int n,int num[]) {
    for (int i = 0; i < 4;i++) {
        num[i] = n % 10;
        n /= 10;
    }
}

int toNumber(int num[]) {
    int sum = 0;
    for (int i = 0; i < 4;i++) {
        sum = sum*10 + num[i] ;
    }
    return sum;
}

int main() {
    int n, num[4];
    int min, max;
    cin >> n;

    while(1) {
        toArray(n, num);
        sort(num, num + 4);
        min = toNumber(num);
        sort(num, num + 4, cmp);
        max = toNumber(num);
        n = max - min;
        printf("%04d - %04d = %04d\n", max, min, n);
        if(n == 0 || n == 6174)
            break;
    }

    return 0;
}