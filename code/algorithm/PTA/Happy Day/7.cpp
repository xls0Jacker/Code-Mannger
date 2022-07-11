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
int n;
struct P{
    int v,num=0;
}P[MAX];

int check(int m){
    int Num=0;
    Rep(1,i,n){
        if(P[i].v==m){
            Num++;
        }
    }
    return Num;
}

void solve(){
    cin>>n;
    int min=0x3f3f3f3f;
    int max=-1;
    Rep(1,i,n){
        cin>>P[i].v;
        if(P[i].v>max){
            max=P[i].v;
        }
        if(P[i].v<min){
            min=P[i].v;
        }
    }
    int Max=check(max);
    int Min=check(min);
    cout<<min<<" "<<Min<<endl;
    cout<<max<<" "<<Max<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

