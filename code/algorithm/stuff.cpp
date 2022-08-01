#include<iostream>
#include"bits/stdc++.h"
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
using namespace std;
#define max 20
typedef struct {
	int size;
	int* data;
}List;
int ListLength(List* psl)
{
	return psl->size;
}
void InitList(List* psl)
{
	//assert(psl != NULL);  //断言
    psl->data = new int[114514];
	//psl->data = NULL;  //初始顺序表为空
	psl->size = 0;  //初始数据个数为0
	//psl->capacity = 0;  //初始空间容量为0
}
int GetElem(List L, int i, int* psl)
{
	if (L.size == 0 || i<0 || i>L.size)
		return 114514;
	else {
		*psl = L.data[i];
		return *psl;
	}
}
void ListInsret(List &L, int i, int m)//每加引用 size++无效
{   
    //cout<<"Pos:"<<i<<endl;
    //cout<<"Size:"<<L.size<<endl;
    if (i<0 || i>L.size+1){
        cout<<"Insert Position Error!"<<endl;
        return ;
    }
		
    for(int j=L.size-1;j>=i;j--){//包括id位置的元素后移一位
        L.data[j+1]=L.data[j];
    }
    L.size++;
    L.data[i]=m;//在id处插入该值

}
void MergeList(List La, List Lb, List& Lc)
{
	InitList(&Lc);
	int i=0,j=0,k=0;
	int La_len = ListLength(&La);
	int Lb_len = ListLength(&Lb);
    cout<<La_len<<" "<<Lb_len<<endl;
	int ai,bj;
    //意义不明
	// cin >> ai >> bj;
	// while ((i <= La_len) && (j <= Lb_len))  //La和Lb均非空
	// {
	// 	if (ai <= bj)
	// 	{
	// 		ListInsret(Lc, ++k, ai);
	// 		++i;
	// 	}
	// 	else
	// 	{
	// 		ListInsret(Lc, ++k, bj);
	// 		++j;
	// 	}
	// }
	while (i < La_len) {
		GetElem(La, i++, &ai);//改ai的值
		ListInsret(Lc, k++, ai);
	}
	while (j < Lb_len) {
		GetElem(Lb, j++, &bj);
		ListInsret(Lc, k++, bj);
	}
}
void output(List L)
{
	for (int i = 0; i < L.size; i++) {
		cout << L.data[i] << " ";
	}
    cout<<endl;
}
int main()
{
    frep;
	List La;
	InitList(&La);
	List Lb;
	InitList(&Lb);
	int m,n;
	int i = 0;
	cout << "请输出序列所含元素个数" << endl;
	cin >>m;
	cout << endl;
	while (m--)
	{
		cin >> n;
		ListInsret(La, i, n);
		i++;
	}
	i = 0;
	cout << "请输出序列所含元素个数" << endl;
	cin >> m;
	cout  << endl;
	while (m--)
	{
		cin>> n ;
		ListInsret(Lb, i, n);
		i++;
	}
		List Lc;
	MergeList(La,Lb,Lc);
    cout<<"拼接后："<<endl;
	output(Lc);
    frepC;
    system("pause");
    return 0;
}
