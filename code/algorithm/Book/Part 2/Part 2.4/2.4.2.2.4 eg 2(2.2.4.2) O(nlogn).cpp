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
const int MAX_N=2*1e4+10;
int N;
int L[MAX_N];
//Fence Repair
//1<=N<=20000 0<=Li<=50000
void solve(){//O(nlogn做法)
    ll ans=0;
    priority_queue<int,vector<int>,greater<int>> que;
    rep(0,i,N){//O(n)
        que.push(L[i]);
    }
    while(que.size()>1){//O(nlogn)
        int l1,l2;//找出短板与次短板
        l1=que.top();//O(1)
        que.pop();//O(logn)
        l2=que.top();
        que.pop();
        ans+=l1+l2;
        que.push(l1+l2);//O(logn)
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    rep(0,i,N){//O(N)
        cin>>L[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

