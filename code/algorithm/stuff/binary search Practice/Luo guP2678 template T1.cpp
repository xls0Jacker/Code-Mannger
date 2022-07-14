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
const int MAX=1e7;
int L,N,M;
int a[MAX];

bool check(int mid){//找成立的距离最小值的最大值
    int now=0;
    int i=0;
    int cnt=0;
    while(i<N+1){
        i++;
        if(a[i]-a[now]<mid){//该距离不是最小距离的最大值 移除
            cnt++;
        }
        else now=i;
    }
    return cnt<=M;
}

void solve(){
    cin>>L>>N>>M;
    Rep(1,i,N){
        cin>>a[i];
    }
    a[N+1]=L;//岸是最后一块石头
    int l=1,r=L+1;
    while(l+1<r){
        int m=(l+r)/2;
        if(check(m)){
            l=m;
        }
        else {
            r=m;
        }
    }
    cout<<l<<endl;//<=
}

int main(){
    //frep;
    solve();
    //frepC;
    //sys;
    return 0;
}

