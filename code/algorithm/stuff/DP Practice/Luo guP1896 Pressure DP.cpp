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
const int MAX=10;
ll dp[MAX][MAX*MAX*2][1<<MAX];
int status[1<<MAX];
int Num[1<<MAX];
int n,k;//棋盘大小 国王数
int cnt;

int cal(int x){
    int res=0;
    while(x){
        if(x&1) res++;
        x>>=1;//x/=2
    }
    return res;
}

bool check(int x){
    if((x<<1)&x) return false;
    if((x>>1)&x) return false;
    return true;
}

void Init(){//预处理->处理同一行是否合法
    rep(0,i,1<<n) Num[i]=cal(i);
    rep(0,i,1<<n) if(check(i)) status[cnt++]=i;
}

void solve(){
    cin>>n>>k;
    Init();
    dp[0][0][0]=1;
    Rep(1,i,n){
        Rep(1,j,cnt){
            int s1=status[j];
            Rep(1,k1,cnt){
                int s2=status[k1];
                if(s1 & s2) continue;
                if((s1<<1) & s2) continue;
                if((s1>>1) & s2) continue;
                if(s1 & (s2<<1)) continue;
                if(s1 & (s2>>1)) continue;
                Rep(0,u,k) dp[i][u+Num[s2]][s2]+=dp[i-1][u][s1];
            }
        }
    }
    ll ANS=0;
    rep(0,i,1<<n) ANS+=dp[n][k][i];
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

