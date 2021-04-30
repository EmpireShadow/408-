#define maxnum 100
#define maxint 32767

//邻接表无向图的单源最短路算法
bool visited[maxnum];
int Distance[maxnum];
int path[maxnum];
queue<int> q;

void BFS_MIN_Distance(graph g,int v0){
    //初始化
    for(int i=0;i<g.vertixnum;i++){
        visited[i]=FALSE;
        Distance[i]=maxint;
        path[i]=-1
    }
    visited[v0]=TRUE;
    Distance[v0]=0;
    q.push(v0);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(W=graph.vertix[v].fistedge;W;W=W->next){
            if(!visited[W.data]){
                visited[W.data]=TRUE;
                D[W.data]=D[v]+1;
                path[W.data]=v;
                q.push(W.data);
            }
        }
    }
}

//邻接矩阵存储 - 有权图的单源最短路算法
#define maxint 32767
bool visited[maxnum];
int Distance[maxnum];
int path[maxnum];

void Dijkstra(graph g,int v0){
    //初始化
    for(int i=0;i<g.vertixnum;i++){
        visited[i]=FALSE;
        Distance[i]=g.arcs[v0][i];
        if(Distance[i]<maxint) path[i]=v0;
        else path[i]=-1;
    }
    visited[v0]=TRUE;
    Distance[v0]=0;
    //开始循环
    for(int i=1;i<g.vertixnum;i++){
        int min=maxint;
        for(int v=0;v<g.vertixnum;v++){
            if(Distance[v]<min&&!visited[v]){
                w=v;
                min=Distance[v];
            }
        }
        visited[v]=TRUE;
        for(int q=0;q<g.vertixnum;q++){
            if(!visited[q]&&Distance[w]+g.arcs[w][q]<Distance[q]){
                Distance[q]=Distance[w]+g.arcs[w][q];
                path[q]=w;
            }
        }
    }
}

//多源最短路算法

