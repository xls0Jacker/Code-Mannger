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
const int INF = 0x3f3f3f3f;
//差值的最小值 Smallest Difference
//1≤T≤100

int asw;
string str;
void solve(){
    asw = INF;
    vector<int> vec;
    for(int i = 0; i < str.size(); i++){
        if(str[i] != ' '){
            vec.push_back(int(str[i] - '0'));
        }
    }
    sort(vec.begin(), vec.end());
    if(vec.size() == 2){
        cout<<abs(vec[0] - vec[1])<<endl;
        return;
    }
    while(vec[0] == 0){
        next_permutation(vec.begin(), vec.end());
    }
    do{
        int mid = (vec.size() + 1) / 2;
        if(vec[mid]){
            int sum1 = 0, sum2 = 0;
            for(int i = 0; i < mid; i++){
                sum1 = sum1 * 10 + vec[i];
            }
            for(int i = mid; i < vec.size(); i++){
                sum2 = sum2 * 10 + vec[i];
            }
            asw = min(asw, abs(sum1 - sum2));
        }
    }while(next_permutation(vec.begin(), vec.end()));
    cout<<asw<<endl;
    //代价为彩笔
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    int T;
    cin>>T;
    cin.get();//消灭空格！
    while(T--){
        getline(cin, str);
        solve();
    }
    frepC;
    sys;
    return 0;
}
