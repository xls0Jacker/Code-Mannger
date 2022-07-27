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
const int MAX_N=41;
//Crazy Rows
//1<=N<=40

//猜想：
//对于第i行，其至多有i个1存在，
//找到离得最近且满足条件的行，
//进行逐位替换即可
int N;
int M[MAX_N][MAX_N];
int a[MAX_N];
void solve(){
    int res=0;
    rep(0,i,N){
        a[i]=-1;//第i行不含1则设为-1（防止与0产生冲突）
        rep(0,j,N){
            if(M[i][j]==1) a[i]=j;
        }
    }
    rep(0,i,N){
        int pos=-1;//要与第i行交换的位次
        rep(i,j,N){
            if(a[j]<=i){//对于第i行，其至多有i个1存在
                pos=j;
                break;
            }
        }
        for(int j=pos;j>i;j--){
            swap(a[j],a[j-1]);
            res++;
        }
    }
    cout<<res<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    rep(0,i,N){
        rep(0,j,N){
            cin>>M[i][j];
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

