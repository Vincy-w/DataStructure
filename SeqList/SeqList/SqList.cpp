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
	int c = 0;
	int a=0, b=0;
	while (a < La.length && b < Lb.length) {
		if (La.data[a] < Lb.data[b]) {
			Lc.data[c++] = La.data[a++];
		}
		else {
			Lc.data[c++] = Lb.data[b++];
		}
	}
	while (a < La.length) {
		Lc.data[c++] = La.data[a++];
	}
	while (b < Lb.length) {
		Lc.data[c++] = Lb.data[b++];
	}
	Lc.length = c;
	return Lc;
}

/**
* p18-2.08 已知在一维数组A[m+n]中依次存放两个线性表(a1,...,am)和(b1,...,bn)。
* 编写一个函数，将数组中两个顺序表的位置互换，即将(b1,...,bn)放在(a1,...,am)的前面。
*/

/**
* p18-2.09 线性表(a1,...,an)中的元素递增有序且按顺序存储于计算机内。
* 要求设计一个算法，完成用最少时间在表中查找数值为x的元素，
* 若找到，则将其与后续元素位置相交换，
* 若找不到，则将其插入表中并使表中元素仍递增有序。
*/
void FindX(SqList& L,ElemType x) {
	int low = 0, high = L.length - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L.data[mid] == x)break;
		if (L.data[mid] < x)low = mid + 1;
		else high = mid - 1;
	}
	if (L.data[mid] == x && mid != L.length - 1) {
		L.data[mid] = L.data[mid + 1];
		L.data[mid + 1] = x;
	}
	if (low > high) {
		for (int i = ++L.length - 1; i > high+1; i--) {
			L.data[i] = L.data[i - 1];
			L.data[i - 1] = x;
		}
	}
}

/**
* p18-2.10 设将n(n>1)个整数存放到一维数组R中。
* 设计一个在时间和空间两方面都尽可能高效的算法。
* 将R中保存的序列循环左移p(0<p<n)个位置，
* 即将R中的数据由（X0,X1,...,Xn-1）变换为（Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1）。
*/
//算法思想：将X0-Xp-1保存到一个数组中，将Xp-Xn-1前移，将X0-Xp-1复制到末尾
void LeftMove(SqList& L, int p) {

}