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
const int MAX_N = 500;
char M[MAX_N + 1][MAX_N + 1];
int n, k, r, c;
// 操作一个元素对角线上间隔k个的元素
void solve(){
		Rep(1,i,n) {
			Rep(1,j,n) {
				if(abs(i+j-r-c)%k == 0)cout<<'X';
				else cout<<'.';
			}
			cout<<endl;
		}
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	frep;
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k >> r >> c;
		solve();
	}
	frepC;
	sys;
	return 0;
}

