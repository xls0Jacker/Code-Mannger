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
//WA
int n;
char a[5];
void solve(){
    cin>>n;
    string s;
    Rep(1,i,n){
        cin>>s;
        int r=0;//右边界
        int l=s.size()-1;
        int sum=0;
        while(r!=l){
            a[1]=s[r];
            int cnt=1;
            sum++;
            Rep(r,j,l){//数组内查找三位不同字符
                if(cnt==3) break;
                bool f=0;
                Rep(1,t,cnt){
                    if(s[j]==a[t]){
                        f=1;
                    }
                }
                if(!f){//不等于其中的任何一个
                    cnt++;
                    a[cnt]=s[j];
                }
            }
            Rep(r,k,l){//查找边界
                bool f=0;
                Rep(1,t,cnt){//字符可能不足3个
                    if(s[k]==a[t]){
                        f=1;
                    }
                }
                if(f){
                    r=k;
                }
                else break;
            }
        }
        cout<<sum<<endl;
    }
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

