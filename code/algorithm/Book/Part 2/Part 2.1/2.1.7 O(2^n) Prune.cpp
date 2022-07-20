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
const int MAX=1e6;
int a[MAX];
int n,k;
//1<=n<=20 0<=ai<=10^8 0<=k<=10^8
//注意条件改变 此时可考虑剪枝
bool dfs(int i,int sum){//O(2^n) 剪枝
    if(sum>k) return false;//剪枝
    if(i==n) return sum==k;//前n项均计算过返回sum是否与k相等
    if(dfs(i+1,sum)) return true;//不选a[i]
    if(dfs(i+1,sum+a[i])) return true;//选a[i]
    return false;
}
void solve(){//O(2^n)做法
    if(dfs(0,0)) puts("Yes");
    else puts("No");
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){//O(n)
        cin>>a[i];
    }
    cin>>k;
    solve();
    frepC;
    sys;
    return 0;
}

