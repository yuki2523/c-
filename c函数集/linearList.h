#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define ERROR -1

typedef int ElementType;

// 线性表的结构，last从1开始，取值时要用 data[last - 1]
typedef struct list {
	ElementType data[MAXSIZE];
	int last;
} *List;

List makeEmpty();
ElementType findKth(List l, int index);
int find(List l, ElementType value);
int insert(List l, int index, ElementType value);
int deleteIndex(List l, int index);
int length(List l);

// 初始化一个线性表，返回一个指向线性表的指针
List makeEmpty() {
	List l;
	l = (List)malloc(sizeof(struct list));
	l->last = -1;
	return l;
}

// 根据 index 找出线性表对应位置的值，
ElementType findKth(List l, int index) {
	return l->data[index - 1];
}

// 已知 value， 返回在线性表里的 index，如果找不到，返回 ERROR，即-1
int find(List l, ElementType value) {
	int i;
	for (i = 0; i < l->last; i++) {
		if (l->data[i] == value) {
			return i + 1;
		}
	}
	return ERROR;
}

// 在指定位置 index 插入 value，插入成功返回 1，失败返回 0
int insert(List l, int index, ElementType value) {
	int i;
	if (l->last == MAXSIZE - 1) {
		printf("list is full, can't insert a new member\n");
		return 0;
	}
	if (l->last == -1 && index == 1) {
		l->data[index - 1] = value;
		l->last = index;
		return 1;
	}
	if ((index < 1) || (index > l->last + 1)) {
		printf("position is out of range\n");
		return 0;
	}

	for (i = l->last - 1; i >= index - 1; i--) {
		l->data[i + 1] = l->data[i];
	}
	l->data[index - 1] = value;
	l->last++;
	return 1;
}

// 删除指定 index 的值，成功返回 1，否则返回 0
int deleteIndex(List l, int index) {
	int i;
	if ((index < 1) || (index > l->last)) {
		printf("position is out of range\n");
		return 0;
	}
	for (i = index - 1; i < l->last - 1; i++) {
		l->data[i] = l->data[i + 1];
	}
	l->last--;
	return 1;
}

// 返回线性表总长度
int length(List l) {
	return l->last;
}
