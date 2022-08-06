#include"bits/stdc++.h"
using namespace std;
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
#define LIMIT_ULL 100000000000000000//比unsigned ll 最大长度少1
//unsigned long long 最大为 1844674407370955161
const int MAX_N=1000;
const int MAX_K=100;
//凑数问题 Dollar Dayz
//1≤N≤1000,1≤K≤100

//思路：
//定义dp[i][j]为取前i个数凑出j的组合数，有
//dp[i][j]=dp[i-1][j]+dp[i-1][j-i]+...+dp[i-1][0];①

//优化方法：
//取j=j-i,有
//dp[i][j-i]=dp[i-1][j-2*i]+...+dp[i-1][0];②
//此时将②带入①得到：
//dp[i][j]=dp[i-1][j]+dp[i][j-i];

//大数处理：
//定义一个较大的数，超过该数的为高位，不超过的为低位，
//若存储高位的数，就将高位的数每次累加当前数值/这个较大数，
//之后将当前数值%这个较大的数来维护低位的数，
//最后判断高位是否有数来看是否需要拼接

// 0高位 1低位
unsigned long long dp[MAX_K+10][MAX_N+10][2];
int N,K;
void solve(){
    Rep(1,i,K){
        dp[i][0][1]=1;//低位金额为0方法数为1
    }
    Rep(1,i,K){
        Rep(1,j,N){
            if(j<i){
                dp[i][j][1]=dp[i-1][j][1];
                dp[i][j][0]=dp[i-1][j][0];
            }
            else {
                dp[i][j][1]=dp[i-1][j][1]+dp[i][j-i][1];
                dp[i][j][0]=dp[i-1][j][0]+dp[i][j-i][0];
                dp[i][j][0]+=dp[i][j][1]/LIMIT_ULL;//高位进位
                dp[i][j][1]%=LIMIT_ULL;//低位维护
            }
        }
    }
    if(dp[K][N][0]){//高位有数则拼接
        cout<<dp[N][K][0];
    }
    cout<<dp[K][N][1]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>K;
    solve();
    frepC;
    sys;
    return 0;
}
