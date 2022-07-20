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
const int MAX=1005;
int N,R;
int X[MAX];
//Saruman's Army
//1<=N<=1000 0<=R<=1000 0<=Xi<=1000
//从最左边的点开始，给距离为R以内的最远点进行标记
//再以超过标记的点距离R的点为起点，重复循环
void solve(){
    sort(X,X+N);//O(nlogn)
    int i=0,ans=0;
    while(i<N){//比O(n)大
        int s=X[i++];//标记起点
        while(i<N and X[i]<=s+R) i++;
        int p=X[i-1];//标记边界R内的最远点
        while(i<N and X[i]<=p+R) i++;//找下一个起点
        ans++;//标记数目++
    }
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>R;
    rep(0,i,N){
        cin>>X[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

