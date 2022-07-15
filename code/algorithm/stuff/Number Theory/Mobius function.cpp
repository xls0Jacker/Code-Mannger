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
const int MAX=1e6+10;
int N,cnt;
bool isprime[MAX];
int prime[MAX];
int minp[MAX],minpk[MAX];
int mobius[MAX];
void prepare(){//欧拉筛递推莫比乌斯函数
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(int i=2;i<N;i++){
        if(isprime[i]) {
            prime[++cnt]=i;
            mobius[i]=i;
        }
        else {
            if(minpk[i]==i){
                mobius[i]=0;
            }
            else {
                mobius[i]=mobius[i/minpk[i]]*mobius[minpk[i]];
            }
        }
        for(int j=1;j<=cnt and i*prime[j]<N;j++){
            isprime[i*prime[j]]=false;
            minp[i*prime[j]]=prime[j];
            if(minp[i]!=minp[j]){
                minpk[i*prime[j]]=prime[j];
            }
            else {
                minpk[i*prime[j]]=minpk[i]*prime[j];
            }
            if(i%prime[j]==0) break;
        }
    }
}

void solve(){

}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

