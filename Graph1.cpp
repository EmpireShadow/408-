#include <stdio.h>
#include <stdlib.h>
#define maxint 32767
#define maxnum 100

//邻接矩阵
typedef char vertextype;
typedef int arcstype;
typedef struct{
  vertextype vertex[maxnum];
  arcstype arcs[maxnum][maxnum];
  int vertnum,arcnum;
}AMGraph;

//邻接表
typedef struct edge{
  int vertex;
  edge* next;
}edge;

typedef struct vertexNode{
  char data;
  edge* firstedge;
}vertexNode;

typedef struct graph{
  vertexNode arcs[maxnum];
  int vertnum,arcnum;
}graph;


//DFS深度优先搜索
bool visited[maxnum];

void DFSTraverse(graph g){
    for(int i=0;i<g.vertnum;i++)
        visited[i]=FALSE;
    for(int v=0;v<g.vertnum;v++)
        if(!visited[v])
            DFS(g,v);
}

void DFS(graph g,int v){
    visit(v);
    visited[v]=TRUE;
    for(w=firstvert(g,v);w>=0;w=nextvert(g,v))
        if(!visited[w])
            DFS(g,w);
}

//BFS广度优先搜索
bool visited[maxnum];
queue<int> q;

void BFSTraverse(graph g){
    for(int i=0;i<g.vertnum;i++)
        visited[i]=FALSE;
    for(int v=0;v<g.vertnum;v++)
        if(!visited[v])
            BFS(g,v);
}

void BFS(graph g,int v){
    visit(v);
    visited[v]=TRUE;
    q.push(v);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(w=firstvertex(g,v);w>=0;w=nextvertex(g,v,w)){
            if(!visited[w]){
                visit(w);
                visited[w]=TRUE;
                q.push(w);
            }
        }
    }
}
  
