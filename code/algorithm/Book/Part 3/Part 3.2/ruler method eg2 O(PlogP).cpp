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
const int MAX_P = 1e6;
// Jessica's Reading Problem
// 1 <= P <= 1e6

// 思路：
// 同样是求最小区间的长度问题，
// 所以可以考虑尺取法来解决这个问题。
// 计算不同的知识点（值）的个数，
// 判断子序列 [s+1, t] 中是否包含所有知识点，
// 若包含则将 s + 1，删除 s 所包含的知识点，
// 若删除了之后 s 所包含的知识点的数量为 0，
// 则 页数--，再次拓展右侧区间 t
// 不断更新最小值得到答案
int P;
int a[MAX_P];
void solve(){// O(PlogP)
  // 得到不同知识点的数目
  set<int> all;
  rep(0, i, P) {
    all.insert(a[i]);// O(logP)
  }
  int n = all.size();
  // 尺取法
  map<int, int> count;// 计算区间中知识点的出现的次数
  int res = P;
  int s = 0, t = 0, num = 0;
  for(;;) {
    while(t < P and num < n) {// O(P)
      if(count[a[t++]]++ == 0) { // O(logP) map的访问
        num++;
      }
    }
    if(num < n) // 剩余区间知识点数目不足，跳出
      break;
    res = min(res, t - s); // 不断更新最小的页数
    if(--count[a[s++]] == 0) { // 删除的页面恰好使该知识点的出现此时降为 0
      num--; // 此时重新找到新的右侧区间端点 t 
    }
  }

  cout << res << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin >> P;
  rep(0, i, P) {
    cin >> a[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}

