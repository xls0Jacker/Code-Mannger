#include"bits/stdc++.h"
using namespace std;
#define sys system("pause")
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
//邻接表 链式向前星//结构体数组储存
const int MAX=1e3;

struct Edge{
    int u,v;
    int next;
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

int main(){
//遍历A的所有边
    int A;
    for(int i=head[A];i!=0;i=eg[i].next){
        /*内容*/
    }
    sys;
    return 0;
}