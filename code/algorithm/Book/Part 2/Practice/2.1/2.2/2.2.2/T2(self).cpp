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
//盒子 Packets

//思路：
//先装大的盒子，
//对于6，只能装一个，无剩余空间；
//对于5，只能装一个，剩余空间可装1；
//对于4，只能装一个，剩余空间可装5个2，再剩余空间装1；
//对于3，可以装1~3个，
//1个3，可以装5个2，再剩余位置可装1，
//2个3，可以装3个2，再剩余位置可装1，
//3个3，可以装1个2，再剩余位置可装1
//对于2，最多装9个，再剩余位置可装1；
//对于1，最多装36个

int a,b,c,d,e,f;//1 2 3 4 5 6
void solve(){
    int ans=0;
    while(f--){//盒子6不为0
        ans++;
    }
    while(e--){//盒子5不为0
        ans++;
        if(a-(36-25)>=0){//剩余位置装1
            a-=36-25;
        }
        else a=0;
    }
    while(d--){//盒子4不为0
        ans++;
        if(b-5>=0){
            b-=5;
        }
        else {
            int res=20-b*4;
            b=0;
            if(a-res>=0){
                a-=res;
            }
            else {
                a=0;
            }
        }
    }
    while(c!=0){//盒子3不为0
        while(1){
            if(c>=4){
            ans++;
            c-=4;
            }
            else {
                break;
            }
        }
        if(c==0) break;
        ans++;
        if(c==3){
            c=0;
            if(b-1>=0){
                b-=1;
                if(a-5>=0){
                    a-=5;
                }
                else {
                    a=0;
                }
            }
            else {
                b=0;
                if(a-9>=0){
                    a-=9;
                }
                else {
                    a=0;
                }
            }
        }
        else if(c==2){
            c=0;
            if(b-3>=0){
                b-=3;
                if(a-6>=0){
                    a-=6;
                }
                else a=0;
            }
            else {
                int res=18-b*4;
                b=0;
                if(a-res>=0){
                    a-=res;
                }
                else {
                    a=0;
                }
            }
        }
        else if(c==1){
            c=0;
            if(b-5>=0){
                b-=5;
                if(a-7>=0){
                    a-=7;
                }
                else a=0;
            }
            else {
                int res=27-b*4;
                b=0;
                if(a-res>=0){
                    a-=res;
                }
                else {
                    a=0;
                }
            }
        }
    }
    while(b!=0){
        ans++;
        if(b-9>=0){
            b-=9;
        }
        else {
            int res=36-b*4;
            b=0;
            if(a-res>=0){
                a-=res;
            }
            else {
                a=0;
            }
        }
    }
    while(a!=0){
        ans++;
        if(a-36>=0){
            a-=36;
        }
        else {
            a=0;
        }
    }  
    cout<<ans<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    while(cin>>a>>b>>c>>d>>e>>f and (a!=0 or b!=0 or c!=0 or d!=0 or e!=0 or f!=0)){
        solve();
    }
    frepC;
    sys;
    return 0;
}

