#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct node {
	ElementType value;
	struct node *next;
} *Node;

// 堆栈，head进、head出
typedef struct stack {
	Node head;
} *Stack;

Stack createStack();
int stackLength(Stack s);
void stackPush(Stack s, ElementType value);
ElementType stackPop(Stack s);
int stackIsEmpty(Stack s);
void stackEnd(Stack s);

// 创建堆栈，返回一个指向堆栈的指针
Stack createStack() {
	Stack s = (Stack)malloc(sizeof(struct stack));
	s->head = NULL;
	return s;
}

// 返回堆栈的长度
int stackLength(Stack s) {
	int i = 0;
	Node p;
	for (p = s->head; p; p = p->next) {
		i++;
	}
	return i;
}

// 入栈，head进入
void stackPush(Stack s, ElementType value) {
	Node p = (Node)malloc(sizeof(struct node));
	p->value = value;
	p->next = s->head;
	s->head = p;
}

// 出栈，head出，返回出去的值
ElementType stackPop(Stack s) {
	ElementType value = s->head->value;
	Node p = s->head;
	s->head = p->next;
	free(p);
	return value;
}

// 判断堆栈是否为空
int stackIsEmpty(Stack s) {
	return s->head == NULL;
}

// 释放掉堆栈所有节点的内存
void stackEnd(Stack s) {
	Node p, q;
	for (p = s->head; p; p = q) {
		q = p->next;
		free(p);
	}
	p = q = NULL;
	s->head = NULL;
	free(s);
}
