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
const int MAX_V=1e3;
int V;
//Floyd-Warshell
//路径还原//有问题，不要用
int d[MAX_V][MAX_V];

int pass[MAX_V][MAX_V];
void warshall_floyd(){
	Rep(1,k,V)
		Rep(1,i,V)
			Rep(1,j,V)
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					pass[i][j]=k;
				}
}
void print(int i,int j)
{
	if(i==j) return; 
	if(pass[i][j]==0) cout<<i<<" "<<j<<endl;
	else{
		print(i,pass[i][j]);
		print(pass[i][j],j); 
	}
}

const int MAX_N=210,MAX_M=210;
int S[MAX_N][MAX_M];

void solve(){
    memset(S,0x3f,sizeof(S));
    cin>>V;
    Rep(1,i,V){
        Rep(i+1,j,V){
            cin>>S[i][j];
        }
    }
    warshall_floyd();
    cout<<S[1][V]<<endl;
    print(1,V);
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

