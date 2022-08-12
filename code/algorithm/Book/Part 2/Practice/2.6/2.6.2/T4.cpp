#include"bits/stdc++.h"
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int MAX_H=1e6+1;
// Semi-prime H-numbers
// 1≤h≤1000001

//思路：
//首先筛出1~h中所有满足H_Number的数，
//在这个集合中将数给逐步分解，若发现恰好除数和商均为H_Number则不为H_Prime，跳出，//TLE?
//将所有的H_Prime放入一个新的集合中，
//两两相乘看是否满足H_semi_prime的条件，//TLE?
//之后累加得到答案

//果不其然 TLE了

//优化思路：
//用0来标记H_Number,
//用-1标记该合数为奇数个H_Number的乘积，（非1）
//用1标记该合数为偶数个H_Number的乘积，（非1）
//该合数为偶数个H_Number的乘积时，该合数为H_semi_prime（非1）
int vis[MAX_H+1];  //记录数组中的下标是否为两个H-primes组成
int ans[MAX_H+1];  //记录数组到下标的所有数字中的H-semi-primes个数
void prev(){
    memset(vis,0,sizeof(vis));
    //打表，在表中记录所有的H-semi-primes数字
    for(int i=5; i<=MAX_H+1; i+=4)
        for(int j=5; j<=MAX_H+1; j+=4){
            int tmp=i*j;
            if(tmp>MAX_H+1)
                break;
            if(vis[i]==0&&vis[j]==0)//两个非1 H_Number的乘积
                vis[tmp]=1;
            else
                vis[tmp]=-1;
        }
    //打表，在表中记录所有的H-semi-primes数字

    //在ans表中记录从1到下标的范围内H-semi-primes的个数
    int cnt=0;
    for(int i=1; i<=MAX_H+1; ++i){
        if(vis[i]==1)
            cnt++;
        ans[i]=cnt;
    }
}

int h;
int main() {
    frep;
    prev();
    while(cin>>h and h!=0){
        cout<<h<<" "<<ans[h]<<endl;
    }
    frepC;
    sys;
    return 0;
}