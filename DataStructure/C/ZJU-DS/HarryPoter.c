#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex; //顶点下标表示顶点
typedef int WeightType; //边的权值

/*-----边的定义-------*/
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;  //有向边V1,V2
    WeightType Weight;  //权重
};
typedef PtrToENode Edge;

/*----图结点的定义-----*/
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];   //邻接矩阵
};
typedef PtrToGNode MGraph;  //以邻接矩阵存储的图类型

MGraph CreateGraph (int VertexNum)
{   //初始化一个有VertexNum个顶点但是没有边的图
    Vertex V,W;
    MGraph Graph;
    
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    //初始化邻接矩阵，注意顶点编号从0开始
    for(V = 0;V<Graph->Nv; V++)
        for(W = 0;W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;
    
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
    MGraph Graph;
    Edge E;
    int Nv,i;

    scanf("%d", &Nv);   //顶点个数
    Graph = CreateGraph(Nv);

    scanf("%d", &(Graph->Ne));
    if(Graph->Ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for(i = 0;i < Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            E->V1--;
            E->V2--;
            InsertEdge( Graph, E);
        }
    }
    return Graph;
}

/*
    Floyd算法
    任意两点间的最短距离
*/
void FLoyd (MGraph Graph, WeightType D[][MaxVertexNum])
{
    Vertex i, j, k;
    
    for(i=0; i<Graph->Nv; i++)
        for(j=0; j<Graph->Nv; j++)
            D[i][j] = Graph->G[i][j];

    for(k=0;k<Graph->Nv; k++)
        for(i=0;i<Graph->Nv;i++)
            for(j=0;j<Graph->Nv;j++) {
                if(D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    if(i == j && D[i][j] < 0)
                        return ;
                }
            }
}

WeightType FindMaxDist (WeightType D[][MaxVertexNum], Vertex i, int N)
{
    WeightType MaxDist;
    Vertex j;

    MaxDist = 0;
    for(j = 0; j< N; j++)
        //注意，[i][i]，自己到自己为无穷大
        if(i != j && D[i][j] > MaxDist)
            MaxDist = D[i][j];
    
    return MaxDist;
}

void FindAnimal( MGraph Graph)
{
    WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
    Vertex Animal, i;

    FLoyd( Graph, D);

    MinDist = INFINITY;
    for(i = 0; i<Graph->Nv; i++)
    {
        MaxDist = FindMaxDist(D, i, Graph->Nv);
        //说明，无法从i这种动物里变出所有动物，即不连通
        if( MaxDist == INFINITY) {
            printf("0\n");
            return;
        }
        if(MinDist > MaxDist) {
            MinDist = MaxDist;
            Animal = i + 1; //更新距离，记录编号
        }
    }
    printf("%d %d\n", Animal, MinDist);
} 

int main()
{
    MGraph G = BuildGraph();
    FindAnimal(G);
    
    getchar();
    return 0;
}