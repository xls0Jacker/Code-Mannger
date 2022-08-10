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
// 邮递员问题 Mr. Rito Post Office（多组输入）
// 2≤N≤200 1≤M≤10000 
// 1≤x,y≤N,1≤t≤1000
// 1≤R≤1000

//思路1：
//对于N较小的情况，
//使用Floyd算法，
//找到两两间的最短距离，
//路径还原判断是否经过水路，
//经过水路后更改船的位置（设置在终点且注意第一次不需要返回），
//最后将长度累加即可

//难以实现且思路不正确

//思路2:
//更改Floyd算法，使其满足题目条件

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

