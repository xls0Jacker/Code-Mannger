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
const int MAX_N=805;
//最小标量集
//small:
//1<=n<=8 -1000<=xi,yi<=1000
//Large:
//100<=n<=800 -100000<=xi,yi<=100000

//猜想：
//将任一数组从小到大开始排，
//另一数组从大到小排，
//保证每一次的乘积最小（由于为1e5的数的乘积，所以建议开long long）
int n;
ll v1[MAX_N],v2[MAX_N];
void solve(){
    ll sum=0;
    sort(v1,v1+n);//O(nlogn)
    sort(v2,v2+n,greater<ll>());//O(nlogn)
    rep(0,i,n){
        sum+=v1[i]*v2[i];
    }
    cout<<sum<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){//O(n)
        cin>>v1[i];
    }
    rep(0,i,n){//O(n)
        cin>>v2[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

