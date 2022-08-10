//#include<iostream>
#include"bits/stdc++.h"
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;
void Init(LinkList& L)//初始化链表
{
	L = new LNode;
	//if (L == NULL) return;
	L->next = NULL;
}
void panding(LinkList& L) {
	LinkList P, Q;
	P = L; L = L->next; Q = P;
	free(Q);
}
void output(LinkList p)
{
	while (p) {
		cout << p->data;
		cout << " ";
		p = p->next;
	}
}
void Listlnsert_L(LinkList& L, int i, int e) {
	LinkList p = L; int j = 0;
	while (p && j < i - 1) {
		p = p->next; j++; //寻找第i-1个结点，p指向i-1结点
	}
	if (!p || j > i - 1) {
		cout<<"Error!"<<endl;
		return; //i大于表长+1或者小于1，插入位置非法
	}
	LinkList s = new LNode; s->data = e; //生成新结点s,将结点s的数据域置为e
	s->next = p->next;
	p->next = s;
}
int main() {
	frep;
	LinkList L;
	Init(L);
	cout << "请输入链表L的长度" << endl;
	int m, n,i;
	cin >> m;
	cout << "请输入链表元素" << endl;
	for (i = 0; i < m;i++) {
		cin >> n;
		Listlnsert_L(L,i,n);
	}
	cout << endl;
	output(L);
	panding(L);
	cout << endl;
	output(L);
	frepC;
	system("pause");
}
