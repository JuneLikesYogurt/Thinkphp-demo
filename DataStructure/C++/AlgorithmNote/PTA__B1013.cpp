#include <iostream>
#include <math.h>
using namespace std;

//筛法，Eratosthenes筛法
const int MaxNUM = 10000001;
int prime[MaxNUM] , num = 0;
bool p[MaxNUM] = {0};

void findPrime(int n) {
    for(int i = 2; i < MaxNUM; i++) {
        if(p[i] == false) {
            prime[num++] = i;
            if(num >= n) break;
            //2不是素数，2的倍数也不是素数 
            for(int j = i + i ; j < MaxNUM; j += i)
                p[j] = true;
        }
    }
}


int main() {
    int m, n, pCount = 0;
    cin >> m >> n;
    findPrime(n);
    for(int i = m; i <= n; i++) {
        cout << prime[i - 1];
        pCount++;
        if(pCount % 10 != 0 && i < n)
            cout << " ";
        else
            cout << endl;
    }
    
    return 0;
}