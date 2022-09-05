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
// 最大化平均值
// 1<=k<=m<=1e4
// 1<=wi,vi<=1e6

// 思路:
// 设 C(x) = 选出 k 个物品使单位重量的价值不小于 x
// 故 lb = 0, ub = INF
// 将条件 C(x) 进行转换,有
// 在集合 S 中,其单位重量的价值为:
// ∑vi/∑wi (xi vi ∈ S)
// 故有 ∑vi/∑wi >= x
// 故有 ∑(vi - x*wi) >= 0
// 故 C(x) = (vi - x*wi) 从大到小排取前 k 个是否大于等于 x

int n, k;
int w[MAX_N + 1], v[MAX_N + 1];

double y[MAX_N + 1];
bool C(double x) {
  rep(0,i,n) {
    y[i] = v[i] - x * w[i];
  }

  sort(y, y + n, greater<double>());

  double sum = 0;
  rep(0,i,k) {
    sum += y[i];
  }

  return sum >= 0;
}
void solve(){
  double lb = 0, ub = INF;
  rep(0,i,100) {
    double mid = (lb + ub) / 2;
    if(C(mid))
      lb = mid;
    else
      ub = mid;
  }

  printf("%.2f\n", lb);
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	frep;
  cin >> n >> k;
  rep(0, i, n) {
    cin >> w[i] >> v[i];
  }
  solve();
	frepC;
	sys;
	return 0;
}

