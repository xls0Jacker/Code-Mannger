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
const int MAX=114514;
int N,cnt;
bool isprime[MAX];
int prime[MAX];
void prepare(){//欧拉筛
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<N;i++){
        if(isprime[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt and i*prime[j]<N;j++){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
void solve(){
    cin>>N;
    prepare();
    
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

