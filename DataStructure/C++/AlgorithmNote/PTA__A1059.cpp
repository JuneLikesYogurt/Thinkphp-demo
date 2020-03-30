#include <iostream>
#include <math.h>
using namespace std;

//质因子分解

//筛法，Eratosthenes筛法
const int MaxNUM = 10000001;
int prime[MaxNUM] , primeNum = 0;
bool p[MaxNUM] = {0};

struct factor {
    int x, cnt; //x为质因子，cnt为其个数
} fac[10];

void findPrime(int n) {
    for(int i = 2; i < MaxNUM; i++) {
        if(p[i] == false) {
            prime[primeNum++] = i;
            if(primeNum >= n) break;
            //2不是素数，2的倍数也不是素数 
            for(int j = i + i ; j < MaxNUM; j += i)
                p[j] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;

    if(n == 1)
        cout << "1=1";

    else {
        findPrime(10000);   //求出10000以内的质数

        cout << n << "=";

        int num = 0;
        int sqr = (int)sqrt(n);
        for (int i = 0; prime[i] <= sqr; i++) {
            if (n % prime[i] == 0){                          //如果prime[i]是n的因子
                fac[num].x = prime[i]; //记录该因子
                fac[num].cnt = 0;
                while (n % prime[i] == 0) //计算质因子prime[i]的个数
                {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++; //不同质因子个数加一
            }
        }
        
        if(n != 1) {    //如果无法被根号n以内的质因子除尽
            fac[num].x = n; //那么一定有一个大于根号n的质因子
            fac[num++].cnt = 1;
        }

        for (int j = 0; j < num;j++) {
            cout << fac[j].x;
            if(fac[j].cnt > 1)
                cout << "^" << fac[j].cnt;
            if(j < num - 1)
                cout << "*";
        }
    }
    
    return 0;
}