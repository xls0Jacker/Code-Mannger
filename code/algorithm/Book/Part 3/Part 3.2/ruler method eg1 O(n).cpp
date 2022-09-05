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
const int MAX_N = 1e5;
// Subsequence 
// 10 < n < 1e5
// 0< ai <=1e4 
// S < 1e8

// 优化思路：(尺取法)
// 找到第一个满足 as + as+1 + ... + at-1 >= S 的子序列[s, t)
// 故 as + as+1 + ... + at-2 < S (ai > 0)
// 故 as+1 + as+2 + ... + at`-2 < S
// 故 t` >= t

// 故有以下方法：
// 将子序列的起点 s 每次 +1，之后找满足和大于等于 S 的 t，
// 之后存下该满足条件的子序列的长度，
// 不断更新找到最小的答案
// 此时 t 最多变化 n 次，故其时间复杂度降到了 O(n) 
int n, S;
int a[MAX_N];
void solve(){// O(n)
  int res = n + 1;//设为 n+1 是为了方便之后的不存在的条件的判断
  int s = 0, t = 0, sum = 0;
  for(;;) {
    while(t < n and sum < S) {
      sum += a[t++];
    }
    if(sum<S) //sum加完了都没有满足条件的值成立
      break;
    res = min(res, t - s);
    sum -= a[s++]; // 起点 +1，并且减去原始起点的值
  }
  if(res == n + 1) { // 一次合理的 t 都没有
    cout << 0 << endl;
    return;
  }

  cout << res << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin >> n >> S;
  rep(0, i, n) {
    cin >> a[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}

