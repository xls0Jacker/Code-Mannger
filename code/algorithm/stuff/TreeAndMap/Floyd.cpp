#include"bits/stdc++.h"
using namespace std;
#define sys system("pause")
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
//Floyd //多源最短路//邻接矩阵储存

const int MAX_N=1e3,MAX_M=1e3;
//邻接矩阵//二维数组存储

int S[MAX_N][MAX_M];//通常存距离
//1.连接关系看具体情况
//使用二重循环

//2.查边
bool query_edge(int a,int b){
    return S[a][b];
}

//3.增边
void edge(int a,int b){
    S[a][b]=1;
}
//正式内容 1
int dis[MAX_N][MAX_M];

int main(){
    int n;
    cin>>n;
     //正式内容 2
    memset(S,0x3f,sizeof(S));
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*
        i------------>j                 !!!!!!K J I!!!!!!
        |             |
        k------------->
    */
    sys;
    return 0;
}