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
const int MAX_N = 1e4;
const int INF = 1e9 + 7;
// Cable master
// 1<=N<=1e4 1<=K<=1e4 1<=Li<=1e5

// 思路：
// 套用二分搜索的模型：
// 设 C(x) = 可以得到 K 条长度为 x 的绳子；
// 此时 lb = 0, ub = INF;
// 将条件 C(x) 进行转换，得到：
// C(x) = ( floor(Li/x) 的总和是否大于或等于 K )

int N, K;
double L[MAX_N + 1];

bool C(double x) {// O(N)
  int num = 0;
  rep(0,i,N) {
    num += (int)(L[i] / x);
  }
  return num >= K;
}

void solve(){ // O(N)
  double lb = 0, ub = INF;
  rep(0,i,100) {// 重复判断 直到解的范围足够小 // 100 次即可达到 1e(-30) 的精度，所以一般是足够的
    double mid = (lb + ub) / 2;
    if(C(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  printf("%.2f\n", floor(lb * 100) / 100); // 舍弃小数点后两位之后的数
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	frep;
  cin >> N >> K;
  rep(0,i,N) {
    cin >> L[i];
  }
  solve();
	frepC;
	sys;
	return 0;
}

