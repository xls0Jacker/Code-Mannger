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
int n,m;
struct Orz{
    int first;
    int second;
    bool f=0;
}v[MAX];
bool cmpByp(Orz a,Orz b){
    return a.second<=b.second;
}
bool cmpByv(Orz a,Orz b){
    return a.first<=b.first;
}

int num;
bool check(int mid){
    return mid<num;
}
int bianry(){
    int l=-1,r=n;
    while(l+1!=r){
        int m=(l+r)/2;
        if(check(v[m].first)){
            l=m;
        }
        else r=m;
    }
    return r;
}
int p[MAX];
void solve(){
    cin>>n>>m;
    int value;
    rep(0,i,n){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v,v+n,cmpByv);//值排序 二分用
    rep(0,i,m){
        cin>>num;
        if(v[bianry()].first==num){
            p[i]=v[bianry()].second;//二分到值排序后的值，后得其索引
        }
        else p[i]=MAX;//放逐 防止为0标记错误
    }
    sort(v,v+n,cmpByp);//索引排序 改输出次序用
    rep(0,i,m){
        v[p[i]].f=true;//排序后索引标记
    }
    rep(0,i,n){
        if(v[i].f) cout<<v[i].first<<" ";
    }
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

