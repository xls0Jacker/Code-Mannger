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
const int MAX_H=1e6+1;
// Semi-prime H-numbers
// 1≤h≤1000001

//思路：
//首先筛出1~h中所有满足H_Number的数，
//在这个集合中将数给逐步分解，若发现恰好除数和商均为H_Number则不为H_Prime，跳出，//TLE?
//将所有的H_Prime放入一个新的集合中，
//两两相乘看是否满足H_semi_prime的条件，//TLE?
//之后累加得到答案

//果不其然 TLE了

//优化思路：
//用0来标记H_Number,
//用-1标记该合数为奇数个H_Number的乘积，（非1）
//用1标记该合数为偶数个H_Number的乘积，（非1）
//该合数为偶数个H_Number的乘积时，该合数为H_semi_prime（非1）
int h;
int _Prime[MAX_H+1];
bool is_H_Number[MAX_H+1];
int cnt;//H_Prime的数的个数

ll quick_multiply(ll a,ll b){
    ll ans=0;
    while(b){
        ans=ans+(b%2*a);
        a=a<<1;
        b>>=1;
    }
    return ans;
}

void prev(){
    int sum=1;
    while(sum<=1e6+2){//筛H_Number
        is_H_Number[sum]=true;
        sum+=4;
    }
}
void solve(){
    for(int i=5;i<=h;i+=4){//筛H_Prime
        for(int j=5;j<=i;j+=4){ 
            if(i%j!=0) continue;
            if(is_H_Number[j] and is_H_Number[i/j] and i/j!=1) break;//恰好除数和商均为H_Number则不为H_Prime
            _Prime[cnt++]=i;
        }
    }
    map<ll,bool>M;
    rep(0,i,cnt){//筛H_semi_prime//注意有些数的乘积的答案相同 注意去重//这里用map来去重
        rep(i,j,cnt){
            ll tmp=quick_multiply((ll)_Prime[i],(ll)_Prime[j]);
            if(tmp>h or !is_H_Number[tmp]) continue;
            M[tmp]=true;
        }
    }
    cout<<h<<" "<<M.size()<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    prev();
    while(cin>>h and h!=0){
        memset(_Prime,0,sizeof(_Prime));
        cnt=0;
        solve();
    }
    frepC;
    sys;
    return 0;
}

