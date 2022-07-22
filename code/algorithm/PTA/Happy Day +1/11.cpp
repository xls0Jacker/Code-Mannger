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
const int MAX=1e4+5;
int N,G,K;
struct Stu{
    string ac;
    int v;
}stu[MAX];

bool cmp(Stu a,Stu b){
    if(a.v>b.v){
        return 1;
    }
    else if(a.v==b.v){
        return a.ac<b.ac;
    }
    else return 0;
}
ll sum;
void solve(){
    sort(stu,stu+N,cmp);
    rep(0,i,N){
        if(stu[i].v>=G and stu[i].v<=100){
            sum+=50;
        }
        else if(stu[i].v>=60 and stu[i].v<G){
            sum+=20;
        }
    }
    cout<<sum<<endl;
    int pos=1;//当前位次
    for(int i=0; pos<=K&&i<N; i++){
        if(stu[i].v!=stu[i-1].v)
            pos=i+1;
        if(pos>K)
            break;
        cout<<pos<<' '<<stu[i].ac<<' '<<stu[i].v<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>G>>K;
    rep(0,i,N){
        cin>>stu[i].ac>>stu[i].v;
    }
    solve();
    frepC;
    sys;
    return 0;
}


