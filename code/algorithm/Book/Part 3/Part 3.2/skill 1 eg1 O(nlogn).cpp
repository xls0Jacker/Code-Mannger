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

// 思路：
// 设子序列[s, t) : as as+1 ... at-1，设为S1
// 若S1 >= S，则对于任意 t` > t 的子序列[s,t`) >= S
// 满足二分的思想，找到最小的 t`
// 设 Sum(i) 为前 i 位数字之和，
// 有 Sum(t) - Sum(s) = S1 判断其与 S 的关系
// 转换一下 就是要找第一个大于等于 Sum(s) + S 的位置
// 直接利用 lower_bound 函数即可得到

// 优化思路：
// 将图预先
int n, S;
int a[MAX_N];

int Sum[MAX_N + 1];
void solve(){// O(nlogn)
  rep(0, i, n) {
    Sum[i + 1] = Sum[i] + a[i];
  }

  if(Sum[n] < S) {// 数组之和小于S，无成立的解
    cout << 0 << endl;
    return;
  }

  int res = n;//假设成立的数组长度右端点为最大值 n
  for (int s = 0; Sum[s] + S <= Sum[n]; s++) {// O(nlogn)
    int t = lower_bound(Sum + s, Sum + n, Sum[s] + S) - Sum;
    res = min(res, t - s);// 不断更新最小长度
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

