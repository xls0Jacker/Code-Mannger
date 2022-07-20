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
string s1;
int N;
//字典序最小问题
//1<=N<=2000 字符串S只包含大写英文字符
//按照字典序比较字符串S和将S反转后的字符串S'
//如果S较小，就从S的开头取出一个文字，追加到T的末尾
//如果S'较小，就从S'的开头取出一个文字，追加到T的末尾
void solve(){//O(n^2)
    while(s1.size()){//O(n)
        string s2=s1;//s2为原串 s1为翻转串
        reverse(s1.begin(),s1.end());//O(n)
        if(s2<s1){
            cout<<s2[0];
            s2.erase(s2.begin());//O(logn)O(logn)//忽略不计
        }
        else {
            cout<<s1[0];
            s2.erase(s2.end()-1);
        }
        s1=s2;//还原
    }
    cout<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    cin>>s1;
    solve();
    frepC;
    sys;
    return 0;
}

