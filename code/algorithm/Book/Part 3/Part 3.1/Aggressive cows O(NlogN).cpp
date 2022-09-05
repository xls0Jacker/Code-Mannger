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
const int MAX_N=1e5;
const int INF = 1e9 + 7;
// 最大化最小值问题

// Aggressive cows 
// 2<=N<=1e5
// 2<=M<=N
// 0<=xi<=1e9

// 思路：
// 套用二分搜索的模型：
// 设 C(d) = 可以安排两头牛的位置使其距离不小于 d
// (求满足 C(d) 条件的最大 d )
// 此时 lb = 0, ub = INF;
// 将条件 C(d) 进行转换，得到：
// C(d) = 假如第 i 头牛在 xj 牛舍, 那么第 (i+1) 头牛要在满足
// (xj + d) <= xk 的最小的 xk 牛舍中

int N, M;
int x[MAX_N + 1];

bool C(int d) {
	int last = 0;
	rep(1, i, M) { // 到 M 之前是否还剩余牛舍
		int crt = last + 1;
		while(crt < N and x[crt] - x[last] < d) {
			crt++;
		}
		if(crt == N)
			return false;
		last = crt;
	}
	return true;
}

void solve(){
	sort(x, x + N);

	int lb = 0, ub = INF;
	while(ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if(C(mid))
			lb = mid;
		else
			ub = mid;
	}

	cout << lb << endl;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	frep;
	cin >> N >> M;
	rep(0, i, N) {
		cin >> x[i];
	}
	solve();
	frepC;
	sys;
	return 0;
}

