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
const int MAX_N=1000;
//Radar Installation
//1≤n≤1000

//思路：
//以每一个海岛为中心，画出一个半径为d的⚪（首先对每一个海岛进行判断，若其无法达到则输出-1）
//求出每一个海岛形成的⚪与海岸线的交点，
//每一个海岛形成的交点形成一个区间，
//对于这些区间，每次取能覆盖到的最长的区间，
//若没有任何一个能够覆盖到，则雷达数增加
struct Section
{
	double begin;
	double end;
	bool operator < (const Section& b) const 
	{  
		return begin < b.begin;
	} 
};

int main(){
	int n, d, __id;
	__id = 0;
    frep;
	while(cin >> n >> d && n > 0){
		int result = 0;
		vector<Section> s(n);
		for (int i = 0; i < n; ++i){//预处理 化面积为区间
			double x, y;
			cin >> x >> y;
			if (result == -1){
				continue;
			}
			if (y > d){
				// 如果y比半径大，一定不能覆盖
				result = -1;
				continue;
			}
			double r = sqrt(d * d - y * y);
			s[i].begin = x - r;
			s[i].end = x + r;
		}

		if (result == -1){
			cout << "Case " << ++__id << ": " << result << endl;
			continue;
		}

		sort(s.begin(), s.end());
		double end = -(1e9+7);
		for (vector<Section>::iterator it = s.begin(); it != s.end(); ++it){
			// cout << it->begin << " " << it->end << endl;
			if (end < it->begin){//不合理
				++result;
				end = it->end;
			}
			else if (end > it->end){//取最小结束区间
				end = it->end;
			}
		}
		cout << "Case " << ++__id << ": " << result << endl;
	}
    frepC;
    sys;
    return 0;
}
