#include<stdio.h>
#define MAXSIZE 100000

void Swap(int *a, int *b);
int ScanForMin(int A[], int beg, int end);

void Bubble_Sort(int A[], int N);
void Insertion_Sort( int A[], int N);
void Shell_Sort(int A[], int N);
void Selection_Sort(int A[], int N);
void HeapAdjust(int A[], int i, int len);
void Heap_Sort(int A[], int N);
void Merge(int A[], int left, int mid, int right);
void Merge_Sort(int A[], int start, int end);

int main() {
    int num,i;
    int A[MAXSIZE];
    
    scanf("%d", &num);

    for(i = 0; i < num; i++)
        scanf("%d", &A[i]);

    //sort
    //冒泡
    // Bubble_Sort(A, num);
    //插入
    // Insertion_Sort(A, num);
    //希尔
    // Shell_Sort(A, num);
    //选择排序
    // Selection_Sort(A, num);
    //堆
    // Heap_Sort(A, num);
    //归并(递归)
    Merge_Sort(A, 0,num-1);


    for(i = 0; i < num; i++) {
        printf("%d", A[i]);
        if(i != num-1)
            printf(" ");
    }
    printf("\n");

    getchar();
    return 0;
}
void Swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int ScanForMin(int A[], int beg, int end) {
    int i, pos;
    pos = beg;
    for(i = beg+1; i < end; i++) {
        if(A[pos] > A[i])
            pos = i;
    }
    return pos;
}



void Bubble_Sort( int A[], int N) {
    int i, j, flag;
    //向前冒泡
    for(i = N - 1; i >= 0; i--) {
        flag = 0;
        for(j = 0; j < i; j++) {    //一趟冒泡
            if(A[j] > A[j+1]) {
                Swap(&A[j],&A[j+1]);
                flag = 1;   //标志交换
            }
        }
        if( flag == 0) break;   //没有交换
    }
}
void Insertion_Sort( int A[], int N) {
    int i, j, temp;
    for(i = 1; i < N; i++) {
        temp = A[i];    //新的一个
        //向前搜索，移出空位
        for(j = i; j >0 && A[j - 1] > temp; j--)
            A[j] = A[j - 1];
        A[j] = temp;    //插入
    }
}

void Shell_Sort(int A[], int N) {
    int D, i, j, temp;
    for( D = N / 2; D > 0; D/=2) {  //希尔增量序列，D
        //插入排序
        for(i = D; i < N; i++) {    
            temp = A[i];
            //注意，每次D个来划分，最后的时候避免越界， j - D
            //插入排序，j - 1
            for(j = i; j >= D && A[j - D] > temp; j-=D)
                A[j] = A[j - D];
            A[j] = temp;
        }
    }
}

void Selection_Sort(int A[], int N) {
    int i, MinPosition;
    for(i = 0; i < N; i++) {
        MinPosition = ScanForMin(A, i , N-1);
        Swap(&A[i], &A[MinPosition]);
    }
}

void HeapAdjust(int A[], int i, int len) {
    int child, temp;
    for(temp = A[i]; 2*i+1 < len; i = child) {
        /*  左子节点, chiild, 父节点位置*2+1
        右子节点, child + 1
        */
        child = 2 * i + i;
        // 子节点中较大的那个节点
        if(child != len - 1 && A[child + 1] > A[child])
            child++;

        // 如果较大的节点 > 父节点，那么把该节点上移，替换其父结点
        if(temp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = temp;
}
void Heap_Sort(int A[], int N)
{
    int i;
    /*  调整序列的前半部分（每个有孩子的节点）
        调整完之后是一个大顶堆
        第一个元素是序列的最大元素
    */
    for(i = N/2 -1; i>=0; i--)  //BuildHeap
        HeapAdjust(A, i, N);

    // 从最后一个元素开始对序列进行调整，不断缩小范围知道第一个元素
    for(i = N - 1; i>0; i--) {  //DeleteMax
        /*  把第一个元素和当前最后一个元素交换
            保证挡墙的最后一个位置的元素都是爱现在的这个序列中最大的
        */
        Swap(&A[0], &A[i]);
        // 不断缩小调整heap的范围。每一个调整完毕保证第一个元素是当前序列的最大值
        HeapAdjust(A, 0, i);
    }
}

void Merge(int A[], int start, int mid, int end) {
    int temp[MAXSIZE];
    int Rstart = mid + 1;
    int i = start, j;
    int num = end - start + 1;

    while(start <= mid && Rstart <= end){
        if(A[start] <= A[Rstart])
            temp[i++] = A[start++];
        else
            temp[i++] = A[Rstart++];
    }

    while(start <= mid)
        temp[i++] = A[start++];
    while(Rstart <= end)
        temp[i++] = A[Rstart++];
    
    //将临时数组中排好序的数据，从后往前依次放入数组中
    for(j = 0; j < num; j++,end--)
        A[end] = temp[end];
}


void Merge_Sort(int A[], int start, int end) {
    if(start < end) {
        int i;
        i = (end + start) / 2;
        Merge_Sort(A, start, i);
        Merge_Sort(A, i+1, end);
        Merge(A, start, i, end);
    }
}