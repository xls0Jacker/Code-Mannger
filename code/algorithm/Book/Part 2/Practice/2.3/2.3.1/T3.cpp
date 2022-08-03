#include <iostream>
#include <algorithm>
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
int tree[1000];
int dp[1000][32][2]; // dp[x][y][z]表示第x + 1分的时候经过y次移动站在了z+1树下能吃到的最大苹果数

inline int move(const int &k){
	return k == 0 ? 1 : 0;
}

int main(int argc, char *argv[]){
    frep;
	int T, W;
	cin >> T >> W;
	for (int i = 0; i < T; ++i){
		int t;
		cin >> t;
		tree[i] = t - 1;
	}
	if (tree[0] == 0){
		dp[0][0][0] = 1;
	}
	else{
		dp[0][1][1] = 1;
	}
	for (int i = 0; i < T - 1; ++i){
		for (int j = 0; j <= W; ++j){
			for (int k = 0; k < 2; ++k){
				if (k == tree[i + 1]){
					// 下一个苹果掉在当前树下，那么下一分钟？
					// 站着不动吃一个
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + 1);
					// 移动没吃到，不变
					dp[i + 1][j + 1][move(k)] = max(dp[i + 1][j + 1][move(k)], dp[i][j][k]);
				}
				else{
					// 下一个苹果掉在另一树下，那么下一分钟？
					// 站着不动没吃到
					dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
					// 移动吃一个
					dp[i + 1][j + 1][move(k)] = max(dp[i + 1][j + 1][move(k)], dp[i][j][k] + 1);
				}
			}
		}
	}
	cout << *max_element(dp[T - 1][0], dp[T - 1][0] + (W + 1) * 2) << endl;
    frepC;
    sys;
    return 0;
}