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
struct P{
    string s;
    int num=1;
}E[MAX];
struct Q{
    string s;
    int f=0; 
}Q[MAX];
int n,m;
void check(string t,int pos);
void Sum(string t,int pos);
void together(string s);

bool cmp(P a,P b){
    if(a.num>b.num) return 1;
    else if(a.num==b.num){
        int l=a.s.size();
        rep(1,i,l){
            if(a.s[i]-'\0'<b.s[i]-'\0'){
                return 1;
            }
            else if(a.s[i]-'\0'>b.s[i]-'\0'){
                return 1;
            }
        }
    }
    else return 0;
    return 1;
}
void solve(){
    cin>>n>>m;
    cin.get();
    Rep(1,i,n){
        getline(cin,Q[i].s);
    }
    int cnt=0;
    Rep(1,i,n){
        check(Q[i].s,i);
    }
    Rep(1,i,n){
        if(Q[i].f==0){//不重
            cnt++;
            E[cnt].s=Q[i].s;
        }
        else if(Q[i].f!=0 and Q[i].f!=-1){
            cnt++;
            E[cnt].s=Q[i].s;
            together(Q[i].s);
        }
    }
    Rep(1,i,cnt){//存重数
        Sum(E[i].s,i);
    }
    cout<<cnt<<endl;
    sort(E+1,E+cnt+1,cmp);
    Rep(1,i,cnt){
        cout<<E[i].num<<" "<<E[i].s<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

void check(string t,int pos){//查重
    Rep(1,i,n){
        if(t==Q[i].s and i!=pos) Q[pos].f++;//重
    }
}
void Sum(string t,int pos){
    Rep(1,i,n){
        if(t==Q[i].s) E[pos].num++;
    }
    E[pos].num--;
}
void together(string s){//相同项置为-1
    Rep(1,i,n){
        if(Q[i].s==s){
            Q[i].f=-1;
        }
    }
}