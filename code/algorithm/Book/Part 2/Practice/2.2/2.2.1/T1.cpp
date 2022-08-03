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
const int MAX_N=25000;
//勤劳的牛 Cleaning Shifts
//1≤n≤25000,1≤T≤1000000

//思路：
//第一个区间必选（特判一下，可能开头不成立），
//每次在相交或相邻的区间内选择结束时间最长的区间，（手写cmp）
//计算成立个数即可
int n,T;
int a[MAX_N+1];
typedef pair<int,int> P;
vector<P> st;
bool cmp(P a,P b){
    return a.second > b.second;
}

bool cmp0(P a,P b){
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}

void solve(){
    sort(st.begin(),st.end(),cmp0);//按开始时间从小到大排列
    if(st[0].first!=1){//开头区间特判
        cout<<-1<<endl;
        return;
    }
    int dist=st[0].second;
    int pos=1;//当前区间位次
    int ans=1;
    while(dist<T){
        int cnt=0;
        rep(pos,i,n){
            if(st[i].first>dist+1){
                break;
            }
            cnt++;//合法区间数目
        }
        if(cnt==0){
            cout<<-1<<endl;
            return;
        }
        sort(st.begin()+pos,st.begin()+pos+cnt,cmp);//成立区间选择区间最大值
        dist=st[pos].second;
        pos+=cnt;
        ans++;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    frep;
    cin>>n>>T;
    int x,y;
    rep(0,i,n){
        cin>>x>>y;
        st.push_back({x,y});
    }
    solve();
    frepC;
    sys;
    return 0;
}
