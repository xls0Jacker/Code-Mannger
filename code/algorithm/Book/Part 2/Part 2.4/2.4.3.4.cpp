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
//二叉搜索树的实现//对应 STL set和map
//功能：
//1. 插入一个数值
//2. 查询是否包含某一个数值
//3. 删除某一个数值
struct node{
    int val;
    node*lch,*rch;
};

node*insert(node*p,int x){//插入数值
    if(p==NULL){//本身为空
        node*q =new node;
        q->val=x;
        q->lch=q->rch=NULL;
        return q;
    }
    else {//左侧放比自己小的右侧反之
        if(x<p->val) p->lch=insert(p->lch,x);
        else p->rch=insert(p->rch,x);
        return p;
    }
}

bool find(node*p,int x){//查询数值
    if(p==NULL) return false;//本身为空
    else if(p->val==x) return true;
    else if(p->val<x) return find(p->lch,x);
    else return find(p->rch,x);
}
//1. 如果要删除的节点没有自己的左儿子，那么就把右儿子提上去
//2. 如果要删除的节点的左儿子没有右儿子，那么把左儿子提上去
//3. 以上两种情况都不满足的话，就把左儿子的子孙种最大的节点提到需要删除的节点上
node*remove(node*p,int x){//删除数值
    if(p==NULL) return NULL;
    else if(x<p->val) p->lch=remove(p->lch,x);
    else if(x>p->val) p->rch=remove(p->rch,x);
    else if(p->lch==NULL){//situation 1
        node*q=p->rch;
        delete p;
        return q;
    }
    else if(p->lch->rch==NULL){//situation 2
        node*q=p->lch;
        q->rch=p->rch;
        delete p;
        return q;
    }
    else {
        node*q;//找删除节点左节点子孙的最大值
        for(q=p->lch;q->rch->rch!=NULL;q=q->rch){//situation 3//不断寻找右节点 右节点其下右节点为空时 此右节点为最大子孙节点
            node*r=q->rch;
            q->rch=r->rch;
            r->lch=p->lch;
            r->rch=p->rch;
            delete p;
            return r;
        }
        return p;
    }
}
void solve(){

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

