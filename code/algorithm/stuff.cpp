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
const int INF=1e9+7;

void solve(){
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
    int sum=0;
    double t11=clock();
    do{
        rep(0,i,9){
            //cout<<a[i]<<" ";
        }
        //cout<<endl;
        sum++;
    }while(next_permutation(a,a+13));
    double t12=clock();
    cout<<"数字排列时间:"<<endl<<t12-t11<<endl;
    cout<<t11<<" "<<t12<<endl;
    string s="123456789ABCD";
    double t21=clock();
    do{
        rep(0,i,13){
            //cout<<s[i]<<" ";
        }
        //cout<<endl;
        sum++;
    }while(next_permutation(s.begin(),s.end()));
    double t22=clock();
    cout<<"字符排列时间:"<<endl<<t22-t21<<endl;
    cout<<t21<<" "<<t22<<endl;
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


