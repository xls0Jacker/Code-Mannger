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
void solve(){
    ll n,c,q;
    cin>>n>>c>>q;//字符串长度 拼接次数 查询次数
    string s;//输入字符串
    cin>>s;
    ll left[c+1],right[c+1],diff[c+1];//左右边界 左边界相较上一次的差异
    left[0]=0; right[0]=n;//初始化
    ll l,r;
    Rep(1,i,c){//拼接
        cin>>l>>r;//此次拼接的边界
        l--,r--;//转化为数组下标
        left[i]=right[i-1];//此次左边界转化为上一次的右边界
        right[i]=left[i]+(r-l+1);//更新此次右边界 加上此次的边界长度
        diff[i]=left[i]-l;//左边界增加的长度
    }
    while(q--){//q次询问
        ll k;//位置
        cin>>k;
        k--;//转化为数组下标
        Per(1,i,c){//逐步回到初始字符串 最后输出初始字符串下标
            if(k<left[i]) continue;
            else k-=diff[i];
        }
        cout<<s[k]<<endl;
    }
}

int main(){
    frep;
    int t;
    cin>>t;//样例数
    while(t--){
        solve();
    }
    frepC;
    sys;
    return 0;
}

