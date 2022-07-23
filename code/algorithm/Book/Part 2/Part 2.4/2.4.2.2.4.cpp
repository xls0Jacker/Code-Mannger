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
int sz=0,heap[MAX_N];
//(二叉)堆的实现//对应STL priority_queue
void push(int x){//插入数值
    int i=sz++;
    while(i>0){
        int p=(i-1)/2;//父亲节点
        if(heap[p]<=x) break;//无大小颠倒
        heap[i]=heap[p];//放下父亲节点数值
        i=p;//自己上提
    }
    heap[i]=x;//值上提
}

int pop(){//取出最小值
    int ret=heap[0];//最小值
    int x=heap[sz--];//将堆最后一个节点的数值提到根的数值
    int i=0;
    while(i*2+1<sz){
        int a=i*2+1,b=i*2+2;//左儿子 右儿子
        if(b<sz and heap[b]<heap[a]) a=b;//右儿子合法且较小 将b的位置赋予a，方便后续处理
        if(heap[a]>=x) break;//无大小颠倒
        heap[i]=heap[a];
        i=a;
    }
    heap[i]=x;
    return ret;
}
void solve(){

}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

