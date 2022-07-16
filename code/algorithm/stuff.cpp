#include<bits/stdc++.h>
#define ll long long
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;

void solve(){
    int n, c, q; cin >> n >> c >> q;//字符串长度 拼接次数 查询次数
    string s; cin >> s;//输入字符串

    vector<ll> left(c+1), right(c+1), diff(c+1);//左右边界 左边界相较上一次的差异
    left[0] = 0;//初始化
    right[0] = n;

    for(int i=1; i<=c; ++i){//拼接
        ll l, r; cin >> l >> r;//此次拼接的边界
        l--; r--;//转化为数组下标
        left[i] = right[i-1];//此次左边界转化为上一次的右边界
        right[i] = left[i] + (r-l+1);//更新此次右边界 加上此次的边界长度
        diff[i] = left[i] - l;//左边界增加的长度
    }

    while(q--){//q次询问
        ll k; cin >> k;//位置
        k--;//转化为数组下标
        for(int i=c; i>=1; --i){//逐步回到初始字符串 最后输出初始字符串下标
            if(k < left[i]) continue;
            else k -= diff[i];
        }
        cout << s[k] << "\n";
    }

}

int main(){
    frep;
    int tt; cin >> tt;//样例数
    while(tt--) solve();
    frepC;
    sys;
    return 0;
}