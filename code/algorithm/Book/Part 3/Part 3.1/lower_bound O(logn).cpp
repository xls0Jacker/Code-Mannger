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
const int MAX_N = 1e6;
// lowr_bound
// 1<=n<=1e6 0<=a0<=a1<=...<=an-1<1e9
// 0<=k<=1e9

// 思路：
// 使用二分搜索，每次区间减半。
// 当a[mid] >= k 时，更新区间为 (lb,mid]
// 当a[mid] < k时，更新区间为 (mid,ub]
// 最后 ub 即为答案（保证 ub 合法）

int n,k;
int a[MAX_N+1];
void solve(){ // O(logn)
  int lb = -1, ub = n;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(a[mid] >= k) {
      ub = mid;
    } else {
      lb = mid;
    }
  }

  cout << ub << endl;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	frep;
  cin >> n;
  rep(0,i,n) {
    cin >> a[i];
  }
  cin >> k;
  solve();
	frepC;
	sys;
	return 0;
}

