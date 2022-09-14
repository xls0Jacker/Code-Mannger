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
const int MAX=1e6;
bool used[MAX];
int perm[MAX];
//生成{0,1,2,3,4,....,n-1}的n!种排列
void permutation1(int pos,int n){//手动求出0~(n-1)的全排列//O(n!)
    if(pos==n){
        /*
            对perm进行的操作
            样例如下：
        */
        rep(0,i,n){
            cout<<perm[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //针对perm的第pos个位置，究竟使用0~(n-1)中的哪一个进行循环
    rep(0,i,n){
        if(!used[i]){
            perm[pos]=i;
            used[i]=true;//i被使用
            permutation1(pos+1,n);
            used[i]=false;//复位
        }
    }
    return;
}
//即使有重复的元素也会生成所有的排列
//next_permutation是按照字典序生成下一个排列的
int perm2[MAX];
void permutation2(int n){//利用STL求出0~(n-1)的全排列//O(n!)
    rep(0,i,n){
        perm2[i]=i;
    }
    do{
        /*
            对perm2进行的操作
            样例如下
        */
        rep(0,i,n){
            cout<<perm2[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(perm2,perm2+n));
    return;
}

void solve(){
    int n;
    cin>>n;
    cout<<"permutation1:"<<endl;
    permutation1(0,n);
    cout<<"permutation2:"<<endl;
    permutation2(n);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //frep;
    solve();
    //frepC;
    sys;
    return 0;
}

