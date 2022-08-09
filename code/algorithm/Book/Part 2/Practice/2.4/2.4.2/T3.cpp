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
const int MAX_N=1e5;
// 标记祖先 Marked Ancestor
// 1<=N,Q<=1e5

//思路：
//当遇见M时，将自身标记为祖先，
//这样可以让其祖先更新为其最近祖先（别人的与其相关的祖先也缩短了），
//当遇见Q时，找其根即可（其根可能在寻找过程中，发现中间部分祖先的某一位祖先被更改为自己，
//这样就夹断了，也达到了找最近的 标记的祖先的目的）

//解决方法：
//这里只需要用到并查集的par数组和find函数，
//且find函数做出一定更改，（不在更改x的原始祖先）
//当为M时，par[x]=x,
//当为Q时，答案加和find(x)即可
int par[MAX_N+1];
int find(int x){//查询x的根
    if(par[x]==x){
        return x;
    }
    else {
        return find(par[x]);
    }
}
int N,Q;
void solve(){
    par[1]=1;
    Rep(2,i,N){
        cin>>par[i];
    }
    char sign;
    int x;
    ll sum=0;
    rep(0,i,Q){
        cin>>sign>>x;
        if(sign=='Q'){//找最近的标记祖先
            sum+=find(x);
        }
        else {//将x的祖先标记位其本身，这样后面找上来的数值就在这里夹断了
            par[x]=x;
        }
    }
    cout<<sum<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>N>>Q and N!=0 and Q!=0){
        memset(par,0,sizeof(par));
        solve();
    }
    frepC;
    sys;
    return 0;
}

