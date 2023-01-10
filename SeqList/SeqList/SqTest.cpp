#include "SqList.h"
#include <iostream>
using namespace std;

int main() {
	//int a[] = { 5,2,11,4,6,2 };
	//SqList L;
	//CreatList(L, a, sizeof(a)/sizeof(a[0]));
	////cout<<"最小值为：" << DelMin(L)<<endl;
	//PrintList(L);
	//ReverseList(L);
	//PrintList(L);
	//DelX(L, 2);
	//PrintList(L);
	//int b[] = { 11,13,15,17,19 };
	//int a[] = { 2,4,6,8,20 };
	////int a[] = { 0 };
	////SqList La,Lb;
	//SqList Lb,La;
	//CreatList(Lb, b, sizeof(b) / sizeof(b[0]));
	//CreatList(La, a, sizeof(a) / sizeof(a[0]));
	//cout<<M_Search(La, Lb);
	//LeftMove(Lb, 3);
	//PrintList(Lb);
	//CreatList(La, a, sizeof(a) / sizeof(a[0]));
	//FindX(Lb, 0);
	//PrintList(Lb);
	//DelSToT(Lb, 3, 6);
	//DelSAndT(Lb, 10, 1);
	//DelRepeat(Lb);
	//SqList Lc = MergeList(La, Lb);
	//PrintList(Lc);
	int a[] = { 0,1,2,3,4,5,5,5 };
	SqList A;
	CreatList(A, a, sizeof(a) / sizeof(a[0]));
	//cout << Majority(A);
	cout << findPosMin(A);
	return 0;
}