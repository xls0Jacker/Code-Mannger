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
const int MAX_N = 1e3, MAX_M = 1e3;

int n, m;
int xx[] = {-1, -2, -3, -4};
int yy[] = {1, 2, 3, 4};
char M[MAX_N + 1][MAX_M + 1];
bool vis[MAX_N + 1][MAX_M + 1];
bool C1(int x,int y) {// 判断 1 
  if(M[x][y + 1] == '.') {
    bool f = false;
    int dx = x - 2;
    int dy = y + 2;
    if(dx>0 and dx<=n and !vis[dx][y] and M[dx][y] == '#'){
      rep(0,i,2) {
        int dx = x + xx[i];
        vis[dx][y] == true;
      }
    } else if(dy>0 and dy<=m and !vis[x][dy] and M[x][dy] == '#') {
      rep(0,i,2) {
        int dy = x + xx[i];
        vis[x][dy] == true;
      }
    } else {
      return false;
    }
    return true;
  }
  return false;
}

bool C0(int x,int y) {// 判断 0
  if(M[x][y + 1] == '#') {
    int dx = x - 3;
    int dy = y + 3;
    if((dx>0 and dx<=n and M[dx][y] == '#' and !vis[dx][y]) or (dy>0 and dy<=m and M[x][dy] == '#' and !vis[x][dy])) {
      return false;
    }
    rep(0,i,2) {
      int dx = x + xx[i];
      int dy = y + yy[i];
      vis[dx][y] = true;
      vis[x][dy] = true;
    }
    return true;
  }
  return false;
}

bool C8(int x,int y) {// 判断 0
  if(M[x][y + 1] == '#') {
    int dx = x - 3;
    int dy = y + 3;
    if(dx>0 and dx<=n and M[dx][y] == '#' and !vis[dx][y]) {
      rep(0,i,2) {
        int dy = y + yy[i];
        vis[x][dy] = true;
      }
      rep(0,i,4) {
        int dx = x + xx[i];
        vis[dx][y] = true;
      }
    } else if(dy>0 and dx<=m and M[x][dy] == '#' and !vis[x][dy]) {
      rep(0,i,2) {
        int dx = x + xx[i];
        vis[dx][y] = true;
      }
      rep(0,i,4) {
        int dy = y + yy[i];
        vis[x][dy] = true;
      }
    } else {
      return false;
    }
    return true;
  }
  return false;
}

int num0, num1, num8;
void solve(){
  rep(0,i,n) {
    rep(0,j,m) {
      if(!vis[i][j] and M[i][j] == '#') {
        if(C1(i,j)) {
          num1++;
        } else if(C0(i,j)) {
          num0++;
        } else if(C8(i,j)) {
          num8++;
        }
      }
    }
  }
  cout << num1 << " " << num0 << " " << num8 << endl;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  frep;
  cin >> n >> m;
  rep(0,i,n) {
    rep(0,j,m) {
      cin >> M[i][j];
    }
  }
  solve();
  frepC;
  sys;
  return 0;
}

