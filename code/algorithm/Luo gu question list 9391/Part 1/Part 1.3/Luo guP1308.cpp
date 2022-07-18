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

void solve(){
    string s,Find;
    cin>>Find;
    cin.get();
    getline(cin,s);
    s=' '+s+' ';
    Find=' '+Find+' ';
    transform(Find.begin(), Find.end(), Find.begin(), ::toupper);  
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    int p=s.find(Find,0);
    int cnt=0;
    int i=0;    
    while(s.find(Find,i)!=string::npos){
        cnt++;
        i=s.find(Find,i)+1;
    }
    if(!cnt){
        cout<<"-1"<<endl;
    }
    else cout<<cnt<<" "<<p<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

