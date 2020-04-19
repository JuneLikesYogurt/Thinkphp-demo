#include <iostream>
#include <string>
using namespace std;

//转化为科学计数法，比较是否相同
string deal(string s,int &e, int n) {
    int i = 0;  //s的下标
    // 去掉s的先导零，eg:0000123
    while(s.length() > 0 && s[0] == '0') {
        s.erase(s.begin());
    }
    if(s[0] == '.') {
        s.erase(s.begin());
        //去掉小数点后非零位前的所有零
        while(s.length() > 0 && s[0] == '0') {
            s.erase(s.begin());
            e--;
        }
    } else {
        while(i < s.length() && s[i] != '.') {
            i++;
            e++;
        }
        //碰到小数点后
        if(i < s.length()) {
            s.erase(s.begin() + i); //删除小数点
        }
    }

    //如果前导零删完后长度=0，则改数为0
    if(s.length() == 0){
        e = 0;
    }

    string res;
    int num = 0, j = 0;
    while(num < n) {    //只要精度还未到n
        if(j < s.length())  //只要还有数字，就加到res末位
            res += s[j++];
        else                //否则res末尾添0
            res += '0';
        num++;
    }
    return res;
}


int main() {
    int n;
    string a, b, c, d;
    cin >> n >> a >> b;
    int e1 = 0, e2 = 0;
    c = deal(a, e1, n);
    d = deal(b, e2, n);

    if(c == d && e1 == e2) {    //指数也要相同
        cout << "YES 0." << c << "*10^" << e1 << endl;
    } else {
        cout << "NO 0." << c << "*10^" << e1 << " 0."<< d << "*10^" << e2 << endl;
    }


    return 0;
}