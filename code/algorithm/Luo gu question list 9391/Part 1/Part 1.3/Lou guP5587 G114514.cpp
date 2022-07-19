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
const int MAX=1e4;
void solve(){
    string s;
    vector<string> L;
    while(getline(cin,s) and s!="EOF"){//连接文章
        L.push_back(s);
    }
    vector<string>::iterator it=L.begin();
    ll sum=0;
    while(getline(cin,s) and s!="EOF"){//手打字符
        while(s[0]=='<'){//去除开头退格键
            s.erase(s.begin());
        }
        while((*it)[0]=='<'){//去除开头退格键
            (*it).erase((*it).begin());
        }
        ll Maxlen=min(s.size(),it->size());
        for(ll i=0;i<Maxlen;i++){
            if(s[i+1]=='<'){//处理输入退格键
                s.erase(s.begin()+i+1);
                s.erase(s.begin()+i);
            }
            if((*it)[i+1]=='<'){//处理文章退格键
                (*it).erase((*it).begin()+i+1);
                (*it).erase((*it).begin()+i);
            }
            if(s[i]==(*it)[i]){
                sum++;
            }
        }
        it++;
    }
    double Sec;
    cin>>Sec;
    ll ANS=sum*60.0/Sec+0.5;
    cout<<ANS<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    frep;
    solve();
    frepC;
    sys;
    return 0;
}

