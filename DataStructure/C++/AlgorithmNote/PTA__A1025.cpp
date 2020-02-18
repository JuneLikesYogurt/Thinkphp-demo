#include<iostream>
#include<algorithm>
using namespace std;

struct Student
{
    string name;
    int score;
    int finalRank;
    int localNum;
    int localRank;
}stu[30001];

bool cmp (Student a,Student b) {
    if(a.score != b.score)  //按分数排
        return a.score > b.score;
    else    //分数相同，按准考证大小排
        return a.name < b.name;
}


int main() {
    int n,len = 0, rankNum = 1;
    cin >> n;
    while(n != 0) {
        int k;
        cin >> k;
        len += k; //总人数

        for (int i = len - k; i < len; i++) {
            cin >> stu[i].name >> stu[i].score;
            stu[i].localNum =  rankNum;
        } 
        //组内排序
        sort(stu + len - k, stu + len,cmp);
        //出现同样分数后，重设rank数值
        for (int i = len - k; i < len; i ++){
            stu[i].localRank = i - (len - k) + 1;
        }
        for (int i = len - k + 1; i < len;i++) {
            if(stu[i].score == stu[i-1].score) {
                stu[i].localRank = stu[i - 1].localRank;
            }
        }
        rankNum++;//组数
        n--;
    }
    //组间排序
    sort(stu, stu + len,cmp);
    //出现同样分数后，重设rank数值
    for (int i = 0; i < len; i ++){
        stu[i].finalRank = i + 1;
    }
    for (int i = 1; i < len;i++) {
        if(stu[i].score == stu[i-1].score) {
            stu[i].finalRank = stu[i - 1].finalRank;
        }
    }

    cout << len << endl;
    for (int i = 0; i < len; i++) {
        cout << stu[i].name << " "<< stu[i].finalRank << " "<< stu[i].localNum << " "<< stu[i].localRank << endl;
    }

    return 0;
}