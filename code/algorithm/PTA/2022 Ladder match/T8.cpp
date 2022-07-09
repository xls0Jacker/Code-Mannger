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
int n,k,s;//参赛人数 批次 分数线
const int MAX=1e6;
struct Test{
    int sc;
    bool PAT=false;
}qua[MAX];
bool cmp(Test a,Test b){
    if(a.sc==b.sc){
        if(a.PAT==1 and b.PAT==0){
            return b.sc>a.sc;
        }
        else if(a.PAT==0 and b.PAT==1){
            return a.sc>b.sc;
        }
    }
    return a.sc>b.sc;
}
void solve(){
    cin>>n>>k>>s;
    int score,Psc;
    Rep(1,i,n){//part 1
        cin>>score>>Psc;
        if(score>=175) qua[i].sc=score;
        else qua[i].sc=-1;
        if(Psc>=s){
            qua[i].PAT=true;
        }
    }
    ll ANS=0;
    Rep(1,i,k){
        sort(qua+1,qua+n+1,cmp);
        int tmp=0;
        Rep(1,j,n){
            if(tmp==qua[j].sc and qua[j].PAT==1 and tmp!=-1 and qua[j].sc!=-1){//成绩相同但PAT合格
                ANS++;
                tmp=qua[j].sc;
                qua[j].sc=-1;
            }
            else if(tmp!=qua[j].sc and tmp!=-1 and qua[j].sc!=-1) {//成绩不相同
                ANS++;
                tmp=qua[j].sc;
                qua[j].sc=-1;
            }
            else tmp=qua[j].sc;//成绩相同PAT不合格
        }
    }
    cout<<ANS<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

