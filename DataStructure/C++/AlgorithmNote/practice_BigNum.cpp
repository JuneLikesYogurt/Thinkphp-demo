#include <iostream>
#include <string.h>
using namespace std;
//大数计算

struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));    //将某一块内存中的内容全部设置为指定的值， 通常为新申请的内存做初始化工作
        len = 0;
    }
};

bign change(char str[]) {   //将整数转换为bign
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len;i++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign add(bign a, bign b) {  //高精度a + b
    bign c;
    int carry = 0; //进位
    for (int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0) {
        c.d[c.len++] = carry;
    }
    return c;
}

void printNum(bign a) { //输出bign
    for (int i = a.len - 1; i >= 0; i--) {
        cout << a.d[i];
    }
}


int main() {
    char str1[1000], str2[1000];
    cin >> str1 >> str2;
    bign a = change(str1);
    bign b = change(str2);
    printNum(add(a, b));

    return 0;
}