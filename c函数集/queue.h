#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

typedef int ElementType;

typedef struct node {
	ElementType value;
	struct node *next;
} *Node;

typedef struct queue {
	Node front, rear;
	int length;
} *Queue;

Queue createQueue(int length);
int isFull(Queue q);
int addQueue(Queue q, ElementType value);
int isEmpty(Queue q);
ElementType deleteQueue(Queue q);
void queueEnd(Queue q);

// 生成一个空队列指针，长度是参数
Queue createQueue(int length) {
	Queue q = (Queue)malloc(sizeof(struct queue));
	q->front = q->rear = NULL;
	q->length = length;
	return q;
}

// 判断是否满了
int isFull(Queue q) {
	int flag = 0, i = 0;
	Node p;
	for (p = q->front; p; p = p->next) {
		i++;
	}
	return i == q->length;
}

// 入队，成功返回1，满了返回0
int addQueue(Queue q, ElementType value) {
	if (isFull(q)) {
		return 0;
	}
	Node p = (Node)malloc(sizeof(struct node));
	p->next = NULL;
	p->value = value;
	if (isEmpty(q)) {
		q->front = q->rear = p;
	} else {
		q->rear->next = p;
		q->rear = p;
	}
	return 1;
}

// 判断是否为空
int isEmpty(Queue q) {
	return q->front == NULL;
}

// 出队
ElementType deleteQueue(Queue q) {
	Node p;
	ElementType value;
	if (isEmpty(q)) {
		return ERROR;
	}
	p = q->front;
	value = p->value;
	if (q->front == q->rear) {
		free(p);
		p = q->front = q->rear = NULL;
	} else {
		q->front = p->next;
		free(p);
		p = NULL;
	}
	return value;
}

// 释放掉队列和所有节点的内存
void queueEnd(Queue q) {
	Node p1, p2;
	for (p1 = q->front; p1; p1 = p2) {
		p2 = p1->next;
		free(p1);
	}
	p1 = p2 = NULL;
	q->front = q->rear = NULL;
	free(q);
}
