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
//map （二叉搜索树实现）
void solve(){
    map<int,const char*>m;//声明
    m.insert(make_pair(1,"ONE"));//插入元素
    m.insert(make_pair(10,"TEN"));
    m[100]="HUNDRED";
    map<int,const char*>::iterator ite;//查找元素
    ite=m.find(1);
    puts(ite->second);
    ite=m.find(2);
    if(ite==m.end()) puts("not found");
    else puts(ite->second);
    puts(m[10]);
    m.erase(10);//删除元素
    for(ite=m.begin();ite!=m.end();ite++){//遍历元素
        cout<<ite->first<<" "<<ite->second<<endl;
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

