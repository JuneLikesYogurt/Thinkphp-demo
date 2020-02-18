#include<iostream>
using namespace std;

int main() {
    int n, m;
    int hashStu[200], hashBook[200] = {0};
    cin >> n >> m;
    for (int i = 1; i <= n;i++) {
        cin >> hashStu[i];
        hashBook[ hashStu[i] ]++;
    }
    for (int i = 1; i < m; i++) {
        if(hashBook[ hashStu[i] ] > 1)
            cout << hashBook[ hashStu[i] ] - 1 << endl;
        else
            cout << "BeiJu" << endl;
    }
    return 0;
}