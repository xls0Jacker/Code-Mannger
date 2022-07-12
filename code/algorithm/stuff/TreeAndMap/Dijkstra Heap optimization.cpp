#include"bits/stdc++.h"
using namespace std;
#define sys system("pause")
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
//Dijkstra 堆优化//单源最短路//邻接表储存//O(N*logM)

/*
    注意！
    仅限非负权值使用
*/

const int MAX=1e3;

struct Edge{
    int u,v;
    int next;
    int l;
}eg[MAX];

int head[MAX];//头节点
int counts;//连接数
//1.连接关系看具体情况

//2.查边
bool  query_edge(int a,int b){

}
//3.加边
void add_edge(int a,int b){
    counts++;//头节点a的边数增加
    eg[counts].u=a;eg[counts].v=b;//创建a->b的连接
    eg[counts].next=head[a];//连接上一头节点
    head[a]=counts;//更新头节点
}

//正式内容
int dis[MAX];
bool vis[MAX];
void dijk(int s){//距离及标记初始化
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;//不要掉了
    typedef pair<int,int> pii,mii;
    priority_queue<pii,vector<pii>,greater<pii>> q;//生成小根堆
    q.push(mii(0,s));//压入源点
    while(!q.empty()){//判断堆顶是否走过，走过换下一堆顶
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=eg[i].next){//在该堆中找最短路径
            int v=eg[i].v,l=eg[i].l;
            if(dis[v]>dis[u]+l){
                dis[v]=dis[u]+l;
                q.push(mii(dis[v],v));//压入短点
            }
            
        }
    }
}


int main(){

    sys;
    return 0;
}