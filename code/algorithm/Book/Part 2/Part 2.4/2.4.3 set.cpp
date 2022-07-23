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
//set （二叉搜索树实现）
void solve(){
    set<int>s;//声明
    s.insert(1);//插入元素
    s.insert(5);
    s.insert(3);
    set<int>::iterator ite;//查找元素
    ite=s.find(1);
    if(ite==s.end()) puts("not found");
    else puts("found");

    ite=s.find(2);
    if(ite==s.end()) puts("not found");
    else puts("found");
    s.erase(3);//删除元素
    if(s.count(3)!=0) puts("found");//其他查找元素的方法
    else puts("not found");
    for(ite=s.begin();ite!=s.end();++ite){//遍历所有元素
        cout<<*ite<<endl;
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

