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
	int b[] = { 1,2,3,4,5,7,8,9,12 };
	int a[] = { 0 };
	SqList La,Lb;
	CreatList(Lb, b, sizeof(b) / sizeof(b[0]));
	CreatList(La, a, sizeof(a) / sizeof(a[0]));
	FindX(Lb, 0);
	PrintList(Lb);
	//DelSToT(Lb, 3, 6);
	//DelSAndT(Lb, 10, 1);
	//DelRepeat(Lb);
	//SqList Lc = MergeList(La, Lb);
	//PrintList(Lc);
	return 0;
}