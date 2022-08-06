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
const int MAX_L=2500;
// 防晒霜 Sunscreen
// 1≤C,L≤2500,1≤minSPFi≤maxSPFi≤1000,1≤cnt,SPFi≤1000

//猜想：
//将区间按照开始的时间从小到大排,防晒霜的固定光照强度也从小到大排，
//在满足左边界成立的时候将尽量小的数值给最大边界尽量小的奶牛使用，
//当一瓶防晒霜同时符合多头牛的需求时，将其涂在maxSPFi最小的牛身上，
//最后满足条件的记录答案即可

typedef pair<int,int> P;

int C,L;
void solve(){    
    P qC[MAX_L+1];//存放区间
    P qL[MAX_L+1];
    cin>>C>>L;
    rep(0,i,C){
        cin>>qC[i].first>>qC[i].second;
    }
    rep(0,i,L){
        cin>>qL[i].first>>qL[i].second;//f->固定光强 s->数目
    }
    sort(qC,qC+C);
    sort(qL,qL+L);
    int ans=0;int cnt=0;
    priority_queue<int,vector<int>,greater<int>>q;
    rep(0,i,L){
        while(cnt<C and qC[cnt].first<=qL[i].first){
            q.push(qC[cnt++].second);
        }
        while(q.size() and qL[i].second){
            int Min_MaxL=q.top();
            q.pop();
            if(Min_MaxL>=qL[i].first){
                qL[i].second--;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

