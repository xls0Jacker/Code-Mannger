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
const int MAX=1e3;
string t;
struct Stri{
    int cnt=0;
    string s;
}Str[MAX];
int n;

bool cmp(Stri a,Stri b){
    return a.cnt>=b.cnt;
}

void solve(){
    cin>>t>>n;
    int len=t.size();
    Rep(1,i,n){
        cin>>Str[i].s;
        if(Str[i].s.size()==len){
            rep(0,j,len){
                if(Str[i].s[j]==t[j]){
                    Str[i].cnt++;
                }
            }
        }
    }
    sort(Str+1,Str+n+1,cmp);
    cout<<Str[1].s<<endl;
    Rep(2,i,n){
        if(Str[i].cnt==Str[1].cnt){
            cout<<Str[i].s<<endl;
        }
        else break;
    }
}   

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

