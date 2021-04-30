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

bool Floyd( MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum] )
{
    Vertex i, j, k;

    /* 初始化 */
    for ( i=0; i<Graph->Nv; i++ )
        for( j=0; j<Graph->Nv; j++ ) {
            D[i][j] = Graph->G[i][j];
            path[i][j] = -1;
        }

    for( k=0; k<Graph->Nv; k++ )
        for( i=0; i<Graph->Nv; i++ )
            for( j=0; j<Graph->Nv; j++ )
                if( D[i][k] + D[k][j] < D[i][j] ) {
                    D[i][j] = D[i][k] + D[k][j];
                    if ( i==j && D[i][j]<0 ) /* 若发现负值圈 */
                        return false; /* 不能正确解决，返回错误标记 */
                    path[i][j] = k;
                }
    return true; /* 算法执行完毕，返回正确标记 */
}
