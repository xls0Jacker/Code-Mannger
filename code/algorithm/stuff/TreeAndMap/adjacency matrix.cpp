#include"bits/stdc++.h"
using namespace std;
#define sys system("pause")
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
const int MAX_N=1e6,MAX_M=1e6;
//邻接矩阵//二维数组存储

int S[MAX_N][MAX_M];
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

int main(){
//遍历A的所有边
    int n;//边数
    cin>>n;
    int A;//遍历对象
    for(int i=0;i<n;i++){
        if(S[A][i]){
            /*内容*/
        }
    }
    sys;
    return 0;
}