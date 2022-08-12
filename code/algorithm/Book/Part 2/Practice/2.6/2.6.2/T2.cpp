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
const int MAX_N=1e6+5;
//素数的个数
//n<=1e6

//思路：
//利用埃氏筛打好一个素数表，
//之后利用bfs从末位开搜索找到最小次数

int n;
//埃氏筛法 
//表中剩余数字最小数字是m时，m就是一个素数，
//然后将表中的m倍都划去
int prime[MAX_N];//第i个素数
bool is_prime[MAX_N];//is_prime[i]为true时表示i为素数
int sieve(int n){//O(nloglogn)
    int p=0;//素数的个数
    Rep(0,i,n) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    Rep(2,i,n){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=i*2;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}

string s[MAX_N+1];
int d[MAX_N+1];
string A,B;
void solve(){
    sieve(10000);//打素数表
    //bfs搜索成立次数
    queue<string>q;
    q.push(A);
    d[stoi(A)]=0;
    while(q.size()){
        string p=q.front();q.pop();
        Per(0,i,3){//位次（先改末尾，保证不漏）
            rep(0,j,10){//更改的数字
                string tmp=p;
                if(i==0 and j==0) continue;//首位为0不符合题意
                tmp[i]=j+'0';
                if(!(is_prime[stoi(tmp)])) continue;//非质数不符合题意
                if(d[stoi(tmp)]>d[stoi(p)] or d[stoi(tmp)]!=0 or tmp==A) continue;//次数变大或已经走过 原点特殊处理
                q.push(tmp);
                d[stoi(tmp)]=d[stoi(p)]+1;
            }
        }
    }
    cout<<d[stoi(B)]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int T;
    cin>>T;
    while(T--){
        cin>>A>>B;
        memset(s,0,sizeof(s));
        memset(d,0,sizeof(d));
        solve();
    }
    frepC;
    sys;
    return 0;
}

