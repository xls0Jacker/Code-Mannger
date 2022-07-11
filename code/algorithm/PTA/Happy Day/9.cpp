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
const int MAX=150;
const int Ma=1e6;
int N,M,S;

void solve(){
    char c[Ma];
    memset(c,0,sizeof(c));
    int cnt=1;
    cin>>N>>M>>S;
    queue<char>q[MAX];
    Rep(1,i,N){
        char t;
        Rep(1,j,M){
            cin>>t;
            q[i].push(t);
        }
        cin.get();//消除回车
    }
    int tmp;
    cin>>tmp;
    stack<char>s;
    while(tmp!=-1){
        if(!tmp){
            if(!s.empty()){
                c[cnt]=s.top();
                cnt++;
                s.pop();
            }
        }
        else{
            if(!q[tmp].empty()){
                int l=s.size();
                if(l==S){
                    c[cnt]=s.top();
                    cnt++;
                    s.pop();
                }
                char t;
                t=q[tmp].front();
                q[tmp].pop();
                s.push(t);
            }
        }
        cin>>tmp;
    }
    cnt--;
    Rep(1,i,cnt){
        cout<<c[i];
    }
    cout<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

