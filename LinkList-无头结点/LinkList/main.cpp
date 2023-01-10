#include "LNode.h"

int main() {
	LinkList L;
	InitList(L);
	int a[] ={1,5,12};
	CreatList(L, a, sizeof(a) / sizeof(a[0]));
	PrintList(L);
	return 0;
}