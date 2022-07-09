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
int U,P,A1,A2;
bool P1,P2;
void selector(){
    //part 1
    char S1='N',S2='N';
    if(A1>=U) S1='Y';
    else if(A2>=P) S1='Y',P1=1;//需要2陪同
    else S1='N';
    if(A2>=U) S2='Y';
    else if(A1>=P) S2='Y',P2=1;//需要1陪同
    else S2='N';
    //part 2
    if(P1) cout<<A1<<"-"<<S1<<" "<<A2<<"-"<<S2<<endl<<"qing 2 zhao gu hao 1"<<endl;
    else if(P2) cout<<A1<<"-"<<S1<<" "<<A2<<"-"<<S2<<endl<<"qing 1 zhao gu hao 2"<<endl;
    else if(S1=='Y' and S2=='Y') cout<<A1<<"-"<<S1<<" "<<A2<<"-"<<S2<<endl<<"huan ying ru guan"<<endl;
    else if(S1=='N' and S2=='N') cout<<A1<<"-"<<S1<<" "<<A2<<"-"<<S2<<endl<<"zhang da zai lai ba"<<endl;
    else if(S1=='Y' and S2=='N') cout<<A1<<"-"<<S1<<" "<<A2<<"-"<<S2<<endl<<"1: huan ying ru guan"<<endl;
    else if(S1=='N' and S2=='Y') cout<<A1<<"-"<<S1<<" "<<A2<<"-"<<S2<<endl<<"2: huan ying ru guan"<<endl;
}

void solve(){
    cin>>U>>P>>A1>>A2;
    selector();
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

