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
const float PI=3.141593;
int num;
void selector(int p){
    if(p==1){
        cout<<"I love Luogu!"<<endl;
    }
    else if(p==2){
        cout<<6<<" "<<4<<endl;
    }
    else if(p==3){
        cout<<3<<endl<<12<<endl<<2<<endl;
    }
    else if(p==4){
        printf("%.3lf\n",500*1.0/3);
    }
    else if(p==5){
        cout<<480/32<<endl;
    }
    else if(p==6){
        cout<<sqrt(6*6+9*9)<<endl;
    }
    else if(p==7){
        cout<<110<<endl<<90<<endl<<0<<endl;
    }
    else if(p==8){
        cout<<2*PI*5<<endl<<PI*5*5<<endl<<4*PI*5*5*5*1.0/3<<endl;
    }
    else if(p==9){
        int ANS=1;
        Rep(1,i,3){
            ANS+=1;
            ANS*=2;
        }
        cout<<ANS<<endl;
    }
    else if(p==10){
        cout<<9<<endl;
    }
    else if(p==11){
        cout<<100/1.0/3<<endl;
    }
    else if(p==12){
        cout<<(int)('M'-'A')+1<<endl<<(char)('A'+18-1)<<endl;
    }
    else if(p==13){
        cout<<(int)(pow(4*PI*10*10*10/3+4*PI*4*4*4/3,1.0*1/3))<<endl;
    }
    else if(p==14){
        cout<<10+((100-sqrt(100*100-4*1*2400))/2)<<endl;
    }
}

void solve(){
    cin>>num;
    selector(num);
}

int main(){
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

