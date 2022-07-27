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
const int MAX=2005;
char S[MAX];
int N;
//字典序最小问题
//1<=N<=2000 字符串S只包含大写英文字符
//按照字典序比较字符串S和将S反转后的字符串S'
//如果S较小，就从S的开头取出一个文字，追加到T的末尾
//如果S'较小，就从S'的开头取出一个文字，追加到T的末尾
void solve(){
    int a=0,b=N-1;
    int cnt=0;
    while(a<=b){
        bool left=false;
        for(int i=0;a+i<=b;i++){
            if(S[a+i]<S[b-i]){
                left=true;
                break;
            }
            else if(S[a+i]>S[b-i]){
                left=false;
                break;
            }
        }
        if(left) putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N;
    rep(0,i,N){
        cin>>S[i];
    }
    solve();
    frepC;
    sys;
    return 0;
}

