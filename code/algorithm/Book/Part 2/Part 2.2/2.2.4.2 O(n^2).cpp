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
const int MAX=2*1e4+10;
int N;
int L[MAX];
//Fence Repair
//1<=N<=20000 0<=Li<=50000
//最短节点往下探底，所有最短节点一定有兄弟节点
//最短的节点与次短节点组成兄弟节点
//总开销为每一个叶子节点的深度*长度
void solve(){//O(N^2)做法
    ll ans=0;
    while(N>1){//O(N-1)
        int mii1=0,mii2=1;//预设短板与次短板的位置
        if(L[mii1]>L[mii2]) swap(mii1,mii2);//找短板和次短板位置//O(1)
        rep(2,i,N){//O(N-2)
            if(L[i]<L[mii1]) {
                mii1=mii2;
                mii1=i;
            }
            else if(L[i]<L[mii2]){
                mii2=i;
            }
        }
        int t=L[mii1]+L[mii2];
        ans+=t;
        if(mii1==N-1) swap(mii1,mii2);
        L[mii1]=t;//此时短板长度更新为拼接板
        L[mii2]=L[N-1];//最短板长度设置为与第(N-1)个板相同的值
        N--;//板的总数值减一
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

