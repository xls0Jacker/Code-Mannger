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
const int MAX=1e7;
int a[MAX];
bool vis[MAX];
void solve(){
    int n;
    cin>>n;
    Rep(1,i,n){
        cin>>a[i];
    }
    int cnt=0;
    Rep(1,i,n){
        Rep(1,j,n){
            if(j!=i){
                Rep(1,k,n){
                    if(k!=j and k!=i){
                        if(a[i]==a[j]+a[k] and vis[i]==0){
                            cnt++;
                            vis[i]=1;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;//处理重复的部分
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

