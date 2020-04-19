#include<iostream>
using namespace std;

//对区间[left,right]进行划分
int Partition(int A[],int left,int right) {
    int temp = A[left];
    while(left < right) {
        while(left < right && A[right] > temp)
            right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp)
            left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[],int left,int right) {
    if(left < right) {
        int pos = Partition(A, left, right);
        quickSort(A, left, pos - 1);
        quickSort(A, pos + 1, right);
    }
}

int fun (int n) {
int x = 1, k;
if (n == 1) return x;
for(k = 1;  k < n;  ++k)
x = x + fun(k) * fun(n - k);
return x;
}

int main() {
    int x = fun(5);
    cout << x;
    return 0;
}