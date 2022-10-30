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
	int b[] = { 1,1,3,3,3,5,7,8,8,9,12 };
	SqList Lb;
	CreatList(Lb, b, sizeof(b) / sizeof(b[0]));
	//DelSToT(Lb, 3, 6);
	//DelSAndT(Lb, 10, 1);
	DelRepeat(Lb);
	PrintList(Lb);
	return 0;
}