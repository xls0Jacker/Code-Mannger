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
const int MAX_N=45;
//Crazy Rows
//1<=N<=40

//猜想：
//找到最长边的位置，每次最长边i和其下的最短边j替换，
//对换的次数为(j-i+1)，
//不断重复直到最长边沉底
//猜想错误
int n;
int M[MAX_N][MAX_N];//矩阵
struct vv{
    int len;
    int pos;
};

bool cmp(vv a,vv b){
    return a.len<b.len;
}
void solve(){
    //存边长
    vv a[MAX_N];
    memset(a,0,sizeof(a));
    rep(0,i,n){// O(n^2)
        Per(0,j,n-1){
            if(M[i][j]==1){
                a[i].len=j+1;//从位次还原为长度
                break;
            }
        }
        a[i].pos=i;
    }
    sort(a,a+n,cmp);//O(nlogn)
    int i=a[n-1].pos;
    int ans=0;
    while(i!=n-1){
        rep(0,j,n){
            cout<<a[j].pos<<" "<<i<<endl<<a[j].len<<" "<<a[i].len<<endl;
            if(a[j].pos>i and a[j].len<a[i].len){//Error!
                i=j;
                ans+=(j-i+1);
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    rep(0,i,n){
        rep(0,j,n){
            cin>>M[i][j];
        }
    }
    solve();
    frepC;
    sys;
    return 0;
}

