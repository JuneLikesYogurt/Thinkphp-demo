#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int num;
    char x;
    cin >> num >> x;

    for (int i = 0; i < round(num * 0.5); i++)
    {
        for (int j = 0; j < num; j++) {
            //如果是第一行或最后一行
            if (i == 0 || i == (round(num * 0.5) - 1)) {           
                cout << x;
            }
            else {
                if(j == 0 || j == (num - 1)) {
                    cout << x;
                }
                else {
                    cout << " ";
                }
            }
        }
        //一行输出完成后换行
        cout << endl;
    }
    return 0;
}