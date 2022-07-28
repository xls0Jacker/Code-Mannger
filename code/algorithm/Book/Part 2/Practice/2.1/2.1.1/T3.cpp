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
//Ball
//T组测试
int a[MAX];//存这10个数
bool dfs(int i,int A,int B){//位次 桶A顶端数 桶B顶端数
    if(i==10) return true;//全部放上了
    if(a[i]>A) {
        return dfs(i+1,a[i],B);
    }
    if(a[i]>B) {
        return dfs(i+1,A,a[i]);
    }
    return false;
}

void solve(){
    if(dfs(0,0,0)) puts("YES");
    else puts("NO");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //frep;
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));//O(10)
        rep(0,i,10){
            cin>>a[i];
        }
        solve();
    }
    
    //frepC;
    //sys;
    return 0;
}

