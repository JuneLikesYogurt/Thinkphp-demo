//mooncake
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct mooncake
{
    double store;   //库存
    double sell;    //总售价
    double price;   //单价
}cake[1000];

bool cmp(mooncake a,mooncake b) {
    return a.price > b.price;
}

int main() {
    int N;
    double D, income = 0;
    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        cin >> cake[i].store;
    }
    for (int i = 0; i < N; i++) {
        cin >> cake[i].sell;
        cake[i].price = cake[i].sell / cake[i].store;
    }

    sort(cake, cake + N, cmp);
    for (int i = 0; i < N; i++) {
        if(cake[i].store > D) {
            income += cake[i].price * D;    //只卖需求量那么多的饼
            break;
        } else {
            D -= cake[i].store; //第i种全部卖出
            income += cake[i].sell;
        }
    }

    //固定点方式显示，这里精度指小数位
    cout << fixed << setprecision(2) << income << endl;

    return 0;
}