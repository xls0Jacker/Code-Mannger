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
const int MAX_N=1e6+5;
//素数的个数
//n<=1e6
int n;
//埃氏筛法 
//表中剩余数字最小数字是m时，m就是一个素数，
//然后将表中的m倍都划去
int prime[MAX_N];//第i个素数
bool is_prime[MAX_N];//is_prime[i]为true时表示i为素数
int sieve(int n){//O(nloglogn)
    int p=0;//素数的个数
    Rep(0,i,n) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    Rep(2,i,n){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
void solve(){
    cout<<sieve(n)<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    solve();
    frepC;
    sys;
    return 0;
}

