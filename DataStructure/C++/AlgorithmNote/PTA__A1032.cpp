#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 100010

// 静态链表
struct Word {
    char data;
    int next; //指针域
    bool flag;  //结点是否在第一链表上出现
}words[MAX];


int main() {
    for (int i = 0; i < MAX;i++) {
        words[i].flag = false;
    }
    int word1, word2, num;
    cin >> word1 >> word2 >> num;
    int address, next;
    char data;
    for (int i = 0; i < num;i++) {
        cin >> address >> data >> next;
        words[address].data = data;
        words[address].next = next;
    }

    int p;
    for (p = word1; p != -1;p=words[p].next) {
        words[p].flag = true;   //枚举第一条链表的所有节点，令其出现次数为1
    }
    for (p = word2; p != -1;p = words[p].next) {
        if(words[p].flag == true)
            break;
    }
    if(p != -1) {   //第二条链表还没到结尾，则有共有节点
        printf("%05d", p);  //输出补零
    } else {
        printf("-1");
    }

    return 0;
}