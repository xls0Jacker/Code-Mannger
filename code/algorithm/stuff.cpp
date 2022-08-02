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

bool cmp(pair<int,int> a,pair<int,int> b){
    if(b.first*a.second>a.first*b.second){
        return 0;//T2*D1>T1*D2 //1在前
    }
    else return 1;
}
void solve(){
    pair<int,int> A[10];
    rep(0,i,6){
        cin>>A[i].first>>A[i].second;
    }
    vector<int>v;
    sort(A,A+6,cmp);
    rep(0,i,5){
        v.push_back(2*A[i].second*A[i+1].first);
    }
    int sum=0;
    sum++;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

