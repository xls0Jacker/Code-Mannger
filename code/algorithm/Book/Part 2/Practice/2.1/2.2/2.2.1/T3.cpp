#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9+7;
const int MAXN = 2510;
struct node{
    int s;
    int e;
    int index;
    bool operator<(const node& x)const{
        return e>x.e;
    }
};

bool cmp(node x,node y){
    return x.s<y.s;
}

vector<node> v;
map<int,int> mp;
priority_queue<node> q;

int main(){
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
            cin>>a>>b;
            v.push_back({a,b,i});
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=1;
    q.push(v[0]);
    mp[v[0].index]=cnt++;
    for(int i=1;i<n;i++){
        node f=q.top();
        if(v[i].s>f.e){
            q.pop();
            mp[v[i].index]=mp[f.index];
        }
        else {
            mp[v[i].index]=cnt++;
        }
        q.push(v[i]);
    }
    cout<<cnt-1<<endl;
    for(int i=1;i<=n;++i)
        cout<<mp[i]<<endl;
    return 0;
}