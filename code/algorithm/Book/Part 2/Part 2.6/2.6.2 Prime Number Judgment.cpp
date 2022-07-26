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
//素数判定
//1<=n<=1e9
int n;

//假设输入都是正数
//素性测试 O(sqrt(n))
bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return n!=1;//1为例外
}
//约数枚举 O(sqrt(n))
vector<int>discover(int n){
    vector<int>res;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    return res;
}
//整数分解 O(sqrt(n))//这个咋用暂时不知道
map<int,int>prime_factor(int n){
    map<int,int>res;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ++res[i];
            n/=i;
        }
    }
    if(n!=1) res[n]=1;
    return res;
}
void solve(){
    if(is_prime(n)){
        puts("Yes");
    }
    else puts("No");
    // if(discover(n).size()==2){
    //     puts("Yes");
    // }
    // else puts("No");
    // cout<<discover(n).size()<<endl;
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

