#include <iostream>
#include "SqList.h"
using namespace std;

//创建链表
bool CreatList(SqList& L, int* a, int alen) {
	//判断数组a长度是否合法
	if (alen > MaxSize) {
		cerr << "can not creat!" << endl;
		return false;
	}
	L.length = alen;
	for (int i = 0; i < L.length; i++) {
		L.data[i] = a[i];
	}
	return true;
}

//打印
void PrintList(SqList& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << ' ';
	}
	cout << endl;
}

/**
* p18-2.01从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值。
* 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
*/
int DelMin(SqList& L) {
	if (L.length == 0) {
		cerr << "List is empty!" << endl;
		return -1;
	}
	int min = L.data[0];
	int count = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] < min) {
			min = L.data[i];
			count = i;
		}
	}
	L.data[count] = L.data[--L.length];
	return min;
}

/**
* p18-2.02 设计一个高效算法，将顺序表L的所有元素逆置，要求算法空间复杂度为O(1)。
*/
void ReverseList(SqList& L) {
	for (int i = 0; i < L.length / 2; i++) {
		int temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

/**
* p18-2.03 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，
* 该算法删除线性表中所有值为x的数据元素
*/
void DelX(SqList& L,ElemType x) {
	//for (int i = 0; i < L.length; i++) {
	//	if (L.data[i] == x) {
	//		for (int j = i; j < L.length; j++) {
	//			L.data[j] = L.data[j + 1];
	//		}
	//		--L.length;
	//	}
	//}但是这样时间复杂度不合要求，瞅了眼答案
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] != x) {
			L.data[k++] = L.data[i];
		}
	}
	L.length = k;
}

/**
* p18-2.04 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，
* 若s或t不合理或顺序表为空，则显示出错信息并退出运行
*/
void DelSToT(SqList& L, ElemType s, ElemType t) {
	if (s >= t||L.length==0||s>L.data[L.length-1]||t<L.data[0]) {
		cerr << "Error range" << endl;
		return;
	}
	int start = 0, end = L.length-1;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] <= s) {
			start = i+1;
		}
		if (L.data[i] >= t) {
			end = i; break;
		}
	}
	if (start == end) return;
	int differ = end - start;
	for (int i = start; (i+differ) < L.length; i++) {
		L.data[i] = L.data[i + differ];
	}
	L.length -= differ;
}

/**
* p18-2.05 p18-2.04 从有序顺序表中删除其值在给定值s与t之间
*（包含s和t，要求s<t）的所有元素，
* 若s或t不合理或顺序表为空，则显示出错信息并退出运行
*/
void DelSAndT(SqList& L, int s, int t) {
	if (s >= t || L.length == 0 || s > L.data[L.length - 1] || t < L.data[0]) {
		cerr << "Error range" << endl;
		return;
	}
	int start = 0, end = L.length - 1;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] >= s) {
			start = i; break;
		}
	}
	for (int j = start; j < L.length; j++) {
		if (L.data[j] > t) {
			end = j; break;
		}
	}
	if (start == end) return;
	int differ = end - start;
	for (int i = start; (i + differ) < L.length; i++) {
		L.data[i] = L.data[i + differ];
	}
	L.length -= differ;
}

/**
* p18-2.06 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
*/
void DelRepeat(SqList& L) {
	int now = 0;
	for (int i = 1; i < L.length; i++) {
		if (L.data[i] != L.data[now]) {
			L.data[++now] = L.data[i];
		}
	}
	L.length = now + 1;
}

/**
* p18-2.07 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
*/
SqList MergeList(SqList La, SqList Lb) {
	SqList Lc;
	int a=0, b=0;
	while (a < La.length && b < Lb.length) {
		
	}
}