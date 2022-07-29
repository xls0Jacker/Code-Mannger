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
const int MAX_N=1e6;
const int INF=1e9+7;
//差值的最小值 Smallest Difference
//1≤T≤100

//数组的长度不定 考虑使用字符串存储（预先处理掉空格），
//对于一个字符串的排列（偶数个元素对半分，奇数个元素前多后少），
//前一半减去后一半取绝对值，（注意处理前一个集合的0）
//使用next_permutation函数寻找字符串的下一个排列，
//不断更新得到差值的最大值
int T;//样例数
string s;//数的排列
bool f;//判断奇偶数
int prev(){//预处理
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    if(s.size()%2==1) f=1;//长度为奇数
    return s.size()/2;
}
void solve(){
    int half=prev();//找到数组的一半长度
    int Mincost=INF;
    sort(s.begin(),s.end());
    do{
        string str=s;
        if(str[0]=='0') continue;//排除前一集合0开头的情况
        if(!f) {//排除后一集合0开头的情况
            if(str[half-1]=='0') continue;
        }
        else {
            if(str[half]=='0') continue;
        }
        int PreN,NxtN;//前一集合代表数字 后一集合代表数字
        PreN=stoi(str.substr(0,half));//前半集合转数字
        if(!f) NxtN=stoi(str.substr(half,half));//后半集合转数字（偶）
        else NxtN=stoi(str.substr(half,half+1));//后半集合转数字（奇）
        Mincost=min(Mincost,abs(NxtN-PreN));
    }while(next_permutation(s.begin(),s.end()));
    cout<<Mincost<<endl;
    cout<<"超时！"<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>T;
    cin.get();
    while(T--){
        getline(cin,s);
        solve();
    }
    frepC;
    sys;
    return 0;
}

