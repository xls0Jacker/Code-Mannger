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

bool cmp(P a,P b){
    return a.first>b.first;
}
void solve(){
    P q[MAX_N+1];
    rep(0,i,N){
        cin>>q[i].first>>q[i].second;
    }
    int ans=0;
    sort(q,q+N,cmp);
    int i=0;
    while(i!=N){
        if(q[i].first>=C and q[i].second!=0){//找到所有比其大的值，均可支付一天的价格
            ans+=q[i].second;
            q[i].second=0;
            i++;
        }
        else { //找到最大的不浪费的面值，之后找最小能成立的面值补上；
            ll sum=0;
            bool f=1;
            while(sum<C){
                if(q[i].second==0){//纸张不足且未满足条件
                    f=0;
                    break;
                }
                sum+=q[i].first;
                q[i].second--;
            }
            if(f) {
                sum-=q[i].first;//减去浪费的一张最大面值(当且仅当该面值纸张充裕时)
                q[i].second++;//返还一张
            }
            else {
                i++;//找下一面值
                continue;
            }
            Per(i,j,N-1){//可以到当前位置(从大到小排列，末尾开始找成立的值)
                if(q[j].second*q[j].first+sum>=C){
                    ll res=ceil((C-sum)/1.0/q[j].first);
                    q[j].second-=res;
                    sum+=q[j].first*res;
                    ans++;
                    break;
                }
                else {
                    sum+=q[j].second*q[j].first;
                    q[j].second=0;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>C;
    
    solve();
    frepC;
    sys;
    return 0;
}

