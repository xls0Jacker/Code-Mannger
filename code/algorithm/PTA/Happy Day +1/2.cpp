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
const int MAX=6;
int L,N;
char s[MAX];
//2 L 6 ;1 N 1e5
ll cnt;
void dfs(int pos){
    if(N==0) return;
    if(s[pos]>'a'){
        s[pos]=s[pos]-1;
        N--;
        cnt=0;
        dfs(pos);
    }
    else {
        s[pos]='{';
        pos--;
        cnt++;
        while(s[pos]=='a'){
            s[pos]='z';
            pos--;
            cnt++;
        }
        s[pos]=s[pos]-1;
        dfs(pos+cnt);
    }
    return;
}

void solve(){
    rep(0,i,L-1){
        s[i]='z';
    }
    s[L-1]='{';
    dfs(L-1);
    rep(0,i,L){
        cout<<s[i];
    }
    cout<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>L>>N;
    solve();
    frepC;
    sys;
    return 0;
}

