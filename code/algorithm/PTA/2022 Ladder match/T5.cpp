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
int AA[]={1,2,3,4,5,6};
int BB[]={1,2,3,4,5,6};
int CC[]={1,2,3,4,5,6};
int DD[]={1,2,3,4,5,6};
int EE[]={1,2,3,4,5,6};
int FF[]={1,2,3,4,5,6};
int A,B,C,D,E,F;
int n;
void solve(){
    cin>>A>>B>>C>>D>>E>>F;
    cin>>n;
    AA[A-1]=-1; BB[B-1]=-1; CC[C-1]=-1; DD[D-1]=-1; EE[E-1]=-1; FF[F-1]=-1;
    sort(AA,AA+6,greater<int>());
    sort(BB,BB+6,greater<int>());
    sort(CC,CC+6,greater<int>());
    sort(DD,DD+6,greater<int>());
    sort(EE,EE+6,greater<int>());
    sort(FF,FF+6,greater<int>());
    cout<<AA[n-1]<<" "<<BB[n-1]<<" "<<CC[n-1]<<" "<<DD[n-1]<<" "<<EE[n-1]<<" "<<FF[n-1]<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

