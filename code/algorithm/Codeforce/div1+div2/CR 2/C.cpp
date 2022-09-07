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

int n;
string s;
int cnt,res;// 计算 （ 的数目    计算 )( 的数目
void solve(){
  cnt = count(s.begin(), s.end(), '(');
  int st = s.find('(');//第一个的位置
  int ed = s.rfind('(');//最后一个的位置
  res = 0;
  for(int i = st + 1; i < ed; i++){
    if(s[i] == ')' and s[i+1] == '(') {
      res++;
    }
  }

  cout << cnt - res << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  int t;
  cin >> t;
  while(t--) {
    cin >> n;
    cin >> s;
    solve();
  }
  frepC;
  sys;
  return 0;
}

