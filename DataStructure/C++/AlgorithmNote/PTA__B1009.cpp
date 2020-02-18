#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> v;
    string s;
    while(cin >> s) {
        v.push(s);
    }
    //输完数据后回车，再ctrl+z，再回车
    cout << v.top();
    v.pop();
    while(!v.empty()) {
        cout << " " << v.top();
        v.pop();
    }
    return 0;
}