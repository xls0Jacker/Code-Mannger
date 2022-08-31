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
const int MAX_N=2*1e5;

int a[MAX_N+1];
int n;
queue<int> q[11];
int cnt[11];
void solve(){
  sort(a+1,a+n+1);//使最大的美味值在后面
  Rep(1,i,n) {//统计各权值对应的数目
    cnt[i%10]++;
  }
  int p=0;//分权值压入队列
  Rep(1,i,n) {
    if(!cnt[p]) p++;//该权值剩余数目为0 跳转至下一权值
    cnt[p]--;
    q[p].push(a[i]);
  }
  //输出 注意特况处理前9个（之后权值有2^0）
  int st=1;//一开始为1-9
  while(1) {
    bool f=false;//输出完红跳出循环标记
    Rep(st,i,9) {
      if(!q[i].empty()) {
        cout<<q[i].front()<<" ";
        q[i].pop();
        f=true;
      }
    }
    if(st==1) st=0;//换为从0-9
    if(!f) break;
  }
  cout<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>n;
    Rep(1,i,n) {
      cin>>a[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

