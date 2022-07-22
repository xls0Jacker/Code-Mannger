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
const int MAX=1e4+10;
struct game{
    string nm;
    double v;
    double vv;
}gamer[MAX];
double a[MAX];
double N;
double sum;
bool cmp(game a,game b){
    return a.v<b.v;
}
double Ave(){
    int n=N;
    rep(0,i,n){
        sum+=gamer[i].v;
        gamer[i].vv=gamer[i].v;
    }
    sum/=N;
    sum=(int)sum/2;
    return sum;
}
void pre(){
    double ave=Ave();
    rep(0,i,N){
        gamer[i].v=abs(gamer[i].v-ave);
    }
    int n=N;
    sort(gamer,gamer+n,cmp);
}
void solve(){
    pre();
    cout<<sum<<" "<<gamer[0].nm<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    rep(0,i,N){
        cin>>gamer[i].nm>>gamer[i].v;
    }
    solve();
    frepC;
    sys;
    return 0;
}

