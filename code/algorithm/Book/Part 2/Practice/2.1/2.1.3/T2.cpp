#include"bits/stdc++.h"
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
using namespace std;
const int MAX_N=10;
//倒立三角 Backward Digit Sums
//1≤n≤10,S

//思路:
//对于每一个全排列利用C[i][j]=C[i-1][j]+C[i-1][j+1]的性质求解（向左贴边）
//找到成立的排列就输出退出循环即可，（题目保证一有解）
//可以参考使用STL库中的next_permutation函数求解
int C[MAX_N+1][MAX_N+1];//存位次值
int S;//要求的数值
int n;
void solve(){
    Rep(1,i,n){//初始化（从1开始方便处理）
        C[1][i]=i;
    }
    do{
        Rep(1,i,n){
            Rep(1,j,n-i){
                C[i][j]=C[i-1][j]+C[i-1][j+1];
            }
        }
        if(C[n][1]==S){
            Rep(1,i,n){
                cout<<C[1][i]<<" ";
            }
            break;
        }
    }while(next_permutation(C[1]+1,C[1]+n+1));
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n>>S;
    solve();
    frepC;
    sys;
    return 0;
}

