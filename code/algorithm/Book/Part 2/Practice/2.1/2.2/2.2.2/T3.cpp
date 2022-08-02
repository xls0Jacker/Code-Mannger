#include"bits/stdc++.h"
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
const int INF = 1e9+7;
using namespace std;
int main()
{   int N, C, ans;
    pair<int, int> cost[20];
    frep;
    cin>>N>>C;
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &cost[i].first, &cost[i].second);
    }
    ans = 0;
    sort(cost, cost+N);//小到大
    for(int i = 0; i < N; i++)//处理面值>=C的纸币
    {
        if(cost[i].first >= C)
        {
            ans += cost[i].first / C * cost[i].second;
            cost[i].second = 0;
        }
    }
    while(true)//处理面值<=C的纸币
    {
        int val = C;
        int sum = 0;//当前价值和
        for(int i = N - 1; i >= 0; i--)//从大面值开始找，找到不浪费的值
        {
            if(val && cost[i].second)
            {
                int k = min(val / cost[i].first, cost[i].second);
                if(k)
                {
                    val -= cost[i].first * k;
                    cost[i].second -= k;
                    sum += cost[i].first * k;
                }
            }
        }
        for(int i = 0; i < N; i++)//从小面值开始找 补差值val
        {
            if(val && cost[i].second && cost[i].first > val)
            {
                val = 0;
                sum += cost[i].first;
                cost[i].second--;
                break;
            }
        }
        if(val > 0) break;//中止条件
        ans ++;
    }
    printf("%d\n", ans);
    frepC;
    sys;
    return 0;
}
