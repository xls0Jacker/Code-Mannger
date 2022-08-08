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
const int MAX_C=1e5;
const int INF=1e9+7;
// 奶牛大学 Moo University - Financial Aid
// 1<=N<=19999 N<=C<=1e5 0<=F<=2*1e9 0<=Qi<=1e5

//思路：
//将数组先按照成绩从大到小排，取前N个数的中间的数，
//以其为中心划分为两个区间，
//前一个区间从大往小取，
//后一个区间从小往大取，
//将超过中心长度的值给剔除，
//用数组保存前i个数及后i个数，
//找到使这前i个数奖学金之和+后i个数的奖学金之和+中位数的奖学金<=F成立的中位数即可

//解决方法：
//用数组_lower[i]表示低于其中位数的成绩的数的奖学金之和，
//用数组_upper[i]表示高于其中位数的成绩的数的奖学金之和，
//_lower数组从C-1开始遍历,
//_upper数组从0开始遍历，
//都将奖学金要求最高的同学丢出去，
//未达到要求牛的数组的长度的一半时，均设为INF，(方便后续二分查找)
//最后从0开始遍历，找到第一个成立的中位数即可
int N,C,F;//宿舍数 牛数 基金 
typedef pair<ll,ll> P;
P CQ[MAX_C+1];//成绩 奖学金
ll lower[MAX_C+1],upper[MAX_C+1];
bool cmp(P a,P b){
    return a.first>b.first;
}
void solve(){
    sort(CQ,CQ+C);//按照成绩从大到小排
    int half=N/2;//5/2=2 恰好符合从0开始
    ll total=0;
    priority_queue<ll> qL;
    rep(0,i,C){
        lower[i]=qL.size()==half?total:INF;
        qL.push(CQ[i].second);
        total+=CQ[i].second;
        if(qL.size()>half){
            total-=qL.top();
            qL.pop();
        }
    }
    total=0;
    priority_queue<ll> qU;
    Per(0,i,C-1){
        upper[i]=qU.size()==half?total:INF;
        qU.push(CQ[i].second);
        total+=CQ[i].second;
        if(qU.size()>half){
            total-=qU.top();
            qU.pop();
        }
    }
    Per(0,i,C-1){
        if(lower[i]+CQ[i].second+upper[i]<=F){
            cout<<CQ[i].first<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    cin>>N>>C>>F;
    rep(0,i,C){
        cin>>CQ[i].first>>CQ[i].second;
    }
    solve();
    frepC;
    sys;
    return 0;
}

