#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100

typedef int Vertex;
// typedef int WeightTpye;
typedef struct ENode *PtrToENode;   //边
struct ENode {
    Vertex V1, V2;  //有向边<v1,v2>
    // WeightTpye Weight;  //权重
};
typedef PtrToENode Edge;
typedef struct Gnode *PrtToGNode;   //图
struct Gnode {
    Vertex nv; //顶点数
    Vertex ne; //边数
    Vertex G[MaxVertexNum][MaxVertexNum];
};
typedef PrtToGNode MGraph;
//判断当前节点是否已被访问
int Visit[MaxVertexNum]; 


//队列
typedef int ElemType;
typedef struct {
    ElemType *pBase;
    ElemType front; //队头索引
    ElemType rear;  //队尾索引
    int maxSize;    //当前分配的最大容量
}queue;



/*-----------队列---------*/
void initQueue(queue *PQueue) {
    PQueue->pBase = (ElemType *)malloc(sizeof(ElemType)*MaxVertexNum);
    // if(!PQueue->pBase) {    //内存分配失败
    //     return ;
    // }
    PQueue->front = 0;
    PQueue->rear = 0;
    PQueue->maxSize = MaxVertexNum;
}
int Enqueue(queue *PQueue,ElemType ele){    //入队
    //队满
    if((PQueue->rear+1)%PQueue->maxSize == PQueue->front)
        return 0;
    else {
        PQueue->pBase[PQueue->rear] = ele;
        PQueue->rear = (PQueue->rear+1) % PQueue->maxSize;
    } 

}
int Dequeue(queue *PQueue) { //出队
    Vertex V;
    //队满
    if((PQueue->rear+1)%PQueue->maxSize == PQueue->front)
        return 0;
    else {
        V = PQueue->pBase[PQueue->front];  //先进先出
        PQueue->front = (PQueue->front + 1) % PQueue->maxSize;  //移到下一个位置   
    }
    return V;
}
int IsEmpty(queue *PQueue) {
    //队头==队尾，为空
    if(PQueue->front == PQueue->rear)
        return 1;
    return 0;
}
void destroyQueue(queue *PQueue) {
    free(PQueue);
    PQueue = NULL;
}



/*-----------图----------------*/
MGraph CreateGraph (int VertexNum)
{
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct Gnode));
    Graph->nv = VertexNum;
    Graph->ne = 0;

    for (V = 0; V < Graph->nv; V++)
        for (W = 0; W < Graph->nv; W++)
            Graph->G[V][W] = 0;

    return Graph;
}
void InsertEdge( MGraph Graph, Edge E) {
    //插入边
    Graph->G[E->V1][E->V2] = 1;
    // Graph->G[E->V1][E->V2] = E->Weight;
    //无向图还要继续插入
    Graph->G[E->V2][E->V1] = 1;
    // Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BuildGraph () {
    MGraph Graph;
    Edge E;
    Vertex V;
    int nv, i;

    scanf("%d", &nv);   //顶点数
    Graph = CreateGraph(nv);
    scanf("%d", &(Graph->ne));  //边数
    if(Graph->ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0;i<Graph->ne; i++) {
            scanf("%d %d",&E->V1, &E->V2);
            InsertEdge(Graph ,E);
        }

    }
    return Graph; 
}


/*-------深度广度优先--------------*/
void DFS(Vertex V, MGraph Graph) {    //深度优先
    Vertex W;
    Visit[V] = 1;
    printf(" %d",V);

    for(W = 0; W < V; W++)
        //没有被访问过，且连通
        if(!Visit[W] && Graph->G[V][W] == 1)
            DFS(W,Graph);
}

void BFS(Vertex V, MGraph Graph) {    //广度优先
    Vertex W;
    queue *Q = (queue *)malloc(sizeof(queue));
    Visit[V] = 1;
    initQueue(Q);
    Enqueue(Q, V);
    while(!IsEmpty(Q)) {
        V = Dequeue(Q);
        printf(" %d", V);
        for(W = 0;W < V; W++)
            //没有被访问过，且连通
            if(!Visit[W] && Graph->G[V][W] == 1) {
                Visit[W] = 1;
                Enqueue(Q, W);
            }
    }
    destroyQueue(Q);
}

int main() {
    MGraph Graph;
    Graph = BuildGraph();

    Vertex V;
    for(V = 0; V<Graph->nv; V++) {
        if(Visit[V] == 0) {
            Visit[V] = 1;
            printf("DFS: {");
            DFS(V, Graph);     
            printf(" }\n"); 
        }
    }

    for(V = 0; V<Graph->nv; V++) {
        Visit[V] = 0;
    }

    for(V = 0; V<Graph->nv; V++) {
        if(Visit[V] == 0) {
            Visit[V] = 1;
            printf("BFS: {");        
            BFS(V, Graph    );     
            printf(" }\n"); 
        }
    }

    getchar();
    return 0;
}