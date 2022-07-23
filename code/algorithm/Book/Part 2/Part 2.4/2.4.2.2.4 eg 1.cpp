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
const int MAX_N=10005;
int N,L,P;
int A[MAX_N],B[MAX_N];
//Expedition
//1<=N<=1e4 1<=L<=1e6 1<=P<=1e6 1<=Ai<L 1<=Bi<=100
//换角度思考:
//到加油站时，相当于获得了一次加油的权力
//最少次数就用优先队列存储，每一次取出最大值
void solve(){
    A[N]=L;//视终点为加油站 方便后续操作
    B[N]=0;
    N++;
    priority_queue<int> que;
    int ans=0,pos=0,tank=P;
    rep(0,i,N){//O(n+)
        int d=A[i]-pos;
        while(tank-d<0){
            if(que.empty()){
                cout<<"-1"<<endl;
                return;
            }
            tank+=que.top();
            que.pop();
            ans++;
        }
        tank-=d;
        pos=A[i];
        que.push(B[i]);
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>L>>P;
    rep(0,i,N){//O(n)
        cin>>A[i];
    }
    rep(0,i,N){//O(n)
        cin>>B[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

