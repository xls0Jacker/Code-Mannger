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
const int MAX_N=500,MAX_M=500;
// C. Corners
// 1≤t≤500 2≤n,m≤500

//思路：
//统计1的个数为sum1，
//当均为0时输出0，
//当均为1时输出sum1-2，
//当存在有的0附近存在0时（八个方向）输出sum1，
//其他情况输出sum1-1
char M[MAX_N+1][MAX_M+1];
int n,m;
int xx[]={0,0,1,-1,1,1,-1,-1};//方向数组
int yy[]={1,-1,0,0,1,-1,1,-1};
void solve(){
    int sum1=0;
    int sum0=0;
    rep(0,i,n){
        rep(0,j,m){
            if(M[i][j]=='1') {
                sum1++;
            } else {
                sum0++;
            }
        }
    }
    bool f=false;
    rep(0,i,n){
        rep(0,j,m){
            if(M[i][j]=='0') {
                rep(0,k,8){
                    int dx=i+xx[k];
                    int dy=j+yy[k];
                    if(dx<0 or dx>=n or dy<0 or dy>=m or M[dx][dy]=='1') continue;
                    f=true;
                }
            }
        }
    }
    if(sum0==0) {
        cout<<sum1-2<<endl;
    } else if(sum1==0) {
        cout<<0<<endl;
    } else if(f) {
        cout<<sum1<<endl;
    } else {
        cout<<sum1-1<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int t;
    cin>>t;
    while(t--){
        memset(M,0,sizeof(M));
        cin>>n>>m;
        rep(0,i,n){
            rep(0,j,m){
                cin>>M[i][j];
            }
        }
        solve();
    }
    frepC;
    sys;
    return 0;
}
