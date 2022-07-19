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
const int MAX=1e4;
string s[MAX],t[MAX],s1;
ll n,m,cnt;
void solve(){
    while(getline(cin,s1),s1!="EOF"){
        n++;//读入字符串
		for(char i:s1)if(i=='<'){if(!s[n].empty())s[n].pop_back();}//模拟，如果是退格且string中还有字符就删掉一个
		else s[n].push_back(i);//否则加上去
	}
	while(getline(cin,s1),s1!="EOF"){
		if(++m>n)break;
		for(char i:s1)if(i=='<'){if(!t[m].empty())t[m].pop_back();}
		else t[m].push_back(i);//同上
		for(int i=0;i<min(t[m].size(),s[m].size());i++)cnt+=s[m][i]==t[m][i];//逐位比较
	}
	cin>>m;
	cout<<(ll)(cnt*60.0/m+0.5)<<endl;//输出
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

