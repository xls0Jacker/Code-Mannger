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
// 城市帮派 Find them, Catch them
// 1≤T≤20 1<=N,M<=1e5

//思路：
//将不是一个帮派的连接起来，
//其中奇数项为同一个帮派，偶数项为另一帮派，
//未出现连接关系的（不在同一组的），不详

//解决方法：
//将非同一组的unite连接起来，
//其中根据奇偶性压入不同的动态数组（两个），
//最后判断时，根据是否连接，
//若连接，检测这两个数是否在同一数组中，
//  若在，则为同一帮派，
//  反之，不在同一帮派，
//反之，不详
void solve(){

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

