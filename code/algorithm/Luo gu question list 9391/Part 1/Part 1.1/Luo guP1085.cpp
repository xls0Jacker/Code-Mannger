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
struct Day{
    int num;//当天为周几
    int sum;//当天课程安排时间
}Week[10];

bool cmp(Day a,Day b){
    return a.sum>b.sum;//按既定顺序排序
}

void solve(){
    int arr1,arr2;
    Rep(1,i,7){
        cin>>arr1>>arr2;
        Week[i].num=i;
        if(arr1+arr2>8) Week[i].sum=arr1+arr2;
    }
    sort(Week+1,Week+8,cmp);
    if(Week[1].sum!=0) cout<<Week[1].num<<endl;
    else cout<<0<<endl;
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

