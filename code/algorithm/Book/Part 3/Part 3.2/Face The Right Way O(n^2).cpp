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
const int MAX_N = 5000;
// Face The Right Way
// 1 <= N <= 5000

// 思路：（开关问题）
// 当牛面向前方时，其不需要改变方向，
// 这样，我们每次考虑区间最左端的牛，
// 判断其是否需要改变其方向，
// 若需要则完成一次翻转；
// 之后判断最后一个区间最左端之后的牛是否需要翻转，
// 若需要，则该分法失败
// 反之，统计最少操作次数M及其对应的k

// 优化思路：// 优化掉翻转操作，实质不翻转
// 考虑第 i 头牛时，若 sumi-1 为奇数时，翻转一次（操作数 +1）
// 当 sumi-1 为奇数时，不翻转
// 同时将长度为 k 的数组向右移一位，有
// sumi = sumi-1 + f[i] - f[i - k + 1] （当 i - k + 1 >= 0 时）
int N;
int dir[MAX_N]; // 每头牛的朝向 F ： 0   B ： 1
int f[MAX_N]; // 区间 [i, i + k -1] 是否进行过翻转

int calc(int K) {
  memset(f, 0, sizeof f);
  int res = 0;// 操作次数
  int sum = 0;
  for(int i = 0; i + K <= N; i++) {
    if( (dir[i] + sum) % 2 != 0) {
      res++;
      f[i] = 1;
    }
    sum += f[i];
    if(i - K + 1 >= 0)
      sum -= f[i - K + 1];
  }

  for(int i = N - K + 1; i <= N; i++) { // 判断剩余区间的牛是否存在反向
    if( (dir[i] + sum) % 2 != 0 ) {
      return -1;
    }
    if(i - K + 1 >= 0)
      sum -= f[i - K + 1];
  }

  return res;
}

void solve(){
  int K = -1, M = N;
  Rep(1, k, N) {
    int m = calc(k);
    if(m < M and m >= 0) { // 更新最小操作次数
      M = m;
      K = k;
    }
  }

  cout << K << " " << M << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin >> N;
  char c;
  rep(0, i, N) {
    cin >> c;
    if(c == 'F')
      dir[i] = 0;
    else
      dir[i] = 1;
  }
  solve();
  frepC;
  sys;
  return 0;
}

