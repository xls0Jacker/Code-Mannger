#include"bits/stdc++.h"
using namespace std;
#define sys system("pause")
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
//拓扑排序//队列实现

/*  
    注意！
1.有向无环图适用
2.原理为走一步删除前面走过的位置，至到全部删除只剩一点
3.将其能连接点的权值-1 若权值为0则入队

    拓扑排序共有四个主要步骤：
1.初始化队列，将入度为 00 的节点放入队列。
2.取出队首，遍历其出边，将能够到达的点入度减一，同时维护答案数组。// 一般为dp维护
3.若在此时一个点的入度变为 11，那么将其加入队列。
4.回到第二步，直到队列为空。

*/
const int MAX=1e3;
vector<int> eg[MAX];
//1.连接关系看具体情况
//使用push_back()

//2.查边
bool query_edge(int a,int b){
    for(auto i:eg[a]){
        if(i=b) return true;
    }
    return false;
}
//3.增边
void add_edge(int a,int b){
    eg[a].push_back(b);
}

//正式内容
queue<int> q;
int counts[MAX];//每个节点的入度
int main(){
    int n;//节点数目
    cin>>n;
    for(int i=1;i<=n;i++){
        if(!counts[i]) q.push(i);//将入度为0的点加入队列
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:eg[u]){
            counts[v]--;
            if(!counts[v]) q.push(v);
        }
    }
    sys;
    return 0;
}