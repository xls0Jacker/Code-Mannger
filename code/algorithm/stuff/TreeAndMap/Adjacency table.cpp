#include"bits/stdc++.h"
using namespace std;
#define sys system("pause")
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
//邻接表//结构体动态数组存储
const int MAX=1e3;
struct Edge{
    int u,v;//u->v
    //int q;//权
};
vector<Edge> eg[MAX];
//1.连接关系看具体情况
//使用push_back()

//2.查边
bool query_edge(int a,int b){
    for(auto i:eg[a]){
        if(i.v=b) return true;
    }
    return false;
}
//3.增边
void add_edge(int a,int b){
    eg[a].push_back({a,b});
}

int main(){
//遍历A的所有边
    int n;//边数
    cin>>n;
    int A;//遍历对象
    for(auto i:eg[A]){
        /*内容*/
    }
    sys;
    return 0;
}
