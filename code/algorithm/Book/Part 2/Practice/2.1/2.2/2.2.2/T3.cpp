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
const int MAX_N=20;
//发放工资 Allowance
//1≤N≤20 1≤C≤100,000,000 1≤vi≤100,000,000 1≤bi≤1,000,000

//猜想：
//将所有面值从大往小排，
//当面值>=C时，直接支付一天工资，
//当面值<C时，找到最大的不浪费的面值，
//之后找最小能成立的面值补上即可；

ll N,C;
typedef pair<ll,ll> P;//面值 数量
P q[MAX_N+1];
bool cmp(P a,P b){
    return a.first>b.first;
}
void solve(){
    int ans=0;
    sort(q,q+N,cmp);
    rep(0,i,N){
        if(q[i].first>=C and q[i].second!=0){//找到所有比其大的值，均可支付一天的价格
            q[i].second=0;
            ans+=q[i].second;
        }
        else { //找到最大的不浪费的面值，之后找最小能成立的面值补上；
            int sum=0;
            rep(0,j,q[i].second){

            }
        }
    }
    
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>C;
    rep(0,i,N){
        cin>>q[i].first>>q[i].second;
    }
    solve();
    frepC;
    sys;
    return 0;
}

