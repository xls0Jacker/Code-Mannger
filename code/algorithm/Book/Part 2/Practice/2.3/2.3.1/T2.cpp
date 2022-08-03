#include<bits/stdc++.h> 
#define int long long
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
const int N = 1e6 + 10, mod = 1e9;
//?
int f[N] = {0};
signed main(){
    frep;
	int n;
	while (cin>>n){
		memset(f,0,sizeof(f));
		f[0] = 1;
		for (int i = 1; i <= n; i *= 2){
			for (int j = 1; j <= n; j ++ ){
				if (j >= i){
					f[j] = (f[j - i] + f[j]) % mod;
				}
			}
		}
		cout << f[n] << endl;
	}
    frepC;
    sys;
	return 0;
}