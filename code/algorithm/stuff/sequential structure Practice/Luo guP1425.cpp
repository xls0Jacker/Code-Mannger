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
int s1,s2;
int f1,f2;
void solve(){
    cin>>s1>>f1
        >>s2>>f2;
    int ANS_H=s2-s1;
    if(f2-f1+60<60){
        ANS_H--;
    }
    int ANS_M=(f2-f1+60)%60;
    cout<<ANS_H<<" "<<ANS_M<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

