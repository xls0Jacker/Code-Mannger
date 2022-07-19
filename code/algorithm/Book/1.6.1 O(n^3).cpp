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
const int MAX=105;
int a[MAX];
//n <= 100 a[i]<=1e6
void solve(){//O(n^3)做法
    int n;
    cin>>n;
    Rep(1,i,n){
        cin>>a[i];
    }
    int ANS=0;
    Rep(1,i,n){
        Rep(i+1,j,n){
            Rep(j+1,k,n){
                int Ma=max(a[i],max(a[j],a[k]));
                int len=a[i]+a[j]+a[k];
                int rest=len-Ma;
                if(Ma<rest){
                    ANS=max(ANS,len);
                }
            }
        }
    }
    cout<<ANS<<endl;
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

