#include"bits/stdc++.h"
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;

int u[4] = {0, 5, 3, 1};  
//当6*6中没有3*3时，新箱子，先不考虑放2*2
//当6*6中有一个3*3时，可以放5个2*2
//当6*6中有两个3*3时，可以放3个2*2
//当6*6中有三个3*3时，可以放1个2*2

int main()
{
    frep;
    int n, p1, p2, p3, p4, p5, p6, x , y;
	int space[4] = {0, 5, 3, 1}; // 一个箱子放入几个 3 * 3 后留下的缝隙可以放入几个 2 * 2
	while(true)
	{
		cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
		if(p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0)
		{
			break;
		}
		// 第一次放“放不下第二个该型号”的型号，需要消耗n个箱子
		n = p4 + p5 + p6 + ceil(p3 / 4.0); // 对 3 * 3 的 package 来讲，四个刚好，否则向上取整
		// 计算 4 * 4 的型号和 3 * 3 的型号之间的缝隙可以放下多少个 2 * 2 的型号
		y = 5 * p4 + space[p3 % 4];
		// 2 * 2 的型号填入这些缝隙，如果填不下，再多消耗几个箱子
		if(p2 > y)
		{
			n += ceil((p2 - y) / 9.0); // 多出来的每9个刚好一个箱子
		}
		// 计算现在空了多少个 1 * 1 的位置
		x = 36 * n - 36 * p6 - 25 * p5 - 16 * p4 - 9 * p3 - 4 * p2;
		// 1 * 1 的型号填入这些缝隙，如果填不下，再多消耗几个箱子
		if(p1>x)
		{
			n += ceil((p1 - x) / 36.0);
		}
		cout << n << endl;
        
	}
    frepC;
    sys;
}