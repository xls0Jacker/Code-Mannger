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
//7数码问题 Seven Puzzle

//思路：
//从最终状态0123 4567 bfs遍历得到所有状态，
//使用map<string,int>来存储到达该状态的最小步数，
//string来存储这一个数列，
//需要注意的是，
//string存储 向下就是向右移动4位 向上就是向左移动4位，
//除此之外，不可以从上一层最后一格向右移动 也不可以从下一层第一格向左移动
//每一步可走的条件为 在棋盘内 以及上面所提到的特殊情况，
//每走一步就将两个数码交换，图不同就存入map
string s="01234567";
map<string,int>mp;
int _move[]={-4,4,1,-1};
void bfs(){
    typedef pair<string,int> P;//当前字符串 某一字符所在数位
    queue<P>q;
    q.push(P(s,0));//从0开始
    mp[s]=0;
    while(q.size()){
        P p=q.front();q.pop();
        string curs=p.first;int cur=p.second;
        rep(0,i,4){
            int nxt=cur+_move[i];
            string str=curs;
            swap(str[cur],str[nxt]);//交换数码
            map<string,int>::iterator it=mp.find(str);
            if((nxt<0 or nxt>=8) or (cur==3 and nxt==4) or (cur==4 and nxt==3) or it!=mp.end()) continue;//不符合可走条件
            q.push(P(str,nxt));
            mp[str]=mp[curs]+1;//步数增加
        }
    }
}

void solve(){
    s.erase(remove(s.begin(),s.end(),' '),s.end());//预处理掉字符串中的0
    cout<<mp[s]<<endl;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    frep;
    bfs();
    while(getline(cin,s)){
        solve();
    }
    frepC;
    sys;
    return 0;
}

