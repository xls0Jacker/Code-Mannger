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
// 奶牛大学 Moo University - Financial Aid
// 1<=N<=19999 N<=C<=1e5 0<=F<=2*1e9 0<=Qi<=1e5

//思路：
//将数组先按照成绩从大到小排，取前N个数的中间的数，
//以其为中心划分为两个区间，
//前一个区间按照奖学金从大到小排，
//后一个区间按照奖学金从小到大排，
//先将后一个区间依次数值依次累加直至N/2，
//若成立测输出，
//反之，将前一个区间向移动一位，中间值变为下一位，再次累加，不断重复，直到出现成立的情况为止
int N,C,F;
typedef pair<int,int> P;
P CQ[MAX_C+1];//成绩 奖励
bool cmp(P a,P b){
    return a.first>b.first;
}

struct cmp1{//优先队列重载
	bool operator()(P x,P y)
	{
		return x.second>y.second;//小的优先级高 ,从小到大排 
	}
};

void solve(){
    sort(CQ,CQ+C,cmp);//按照成绩从大到小排
    bool f=0;
    int cnt=0;
    while(!f){
        int sum=0;
        int ans=CQ[N/2+cnt].first;//5/2=2 刚好对应从0开始的中位数
        sum+=CQ[N/2+cnt].second;
        priority_queue<P,vector<P>,cmp1> q;
        rep(cnt,i,N/2+cnt){
            q.push(CQ[i]);
            sum+=CQ[i].second;
        }
        per(C-1-N/2,i,C-1){
            int tmp=sum;
            if(sum+CQ[i].second<=F){
                sum+=CQ[i].second;
                if(i==C-N/2){
                    f=1;
                }
            }
        }
        if(f){
            cout<<ans<<endl;
        }
        else {
            cnt++;//前区间后移一位
            if(N/2+cnt>C-1-N/2){//前区间尾端点大于后区间首端点 不合法
                cout<<-1<<endl;
                return;
            }
        }
    }

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

