#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node *next;
} _Node;

typedef _Node *Node;

typedef struct _list {
    Node head;
} _List;

typedef _List *List;

List listInit();
Node listFindLast(List list);
int listLength(List list);
void listAdd(List list, int value);
void listDelete(List list, int member);
int listFindNodeInner(List list, int value);
int listPrinter(List list);
void listEnd(List list);
Node listFindValue(List list, int value);
void listAddInner(List list, int value, int newValue);

// 初始化链表
List listInit() {
    List list = (List)malloc(sizeof(*list));
    Node head = NULL;
    list->head = head;
    return list;
}

// 找到最后一个节点
Node listFindLast(List list) {
    Node p;
    // printf("%d\n", 1);
    for (p = list->head; p; p = p->next) {
        if (!p->next) {
            return p;
        }
    }
    return p;
}

// 检索 value 值所在的节点,返回那个节点的指针,无则NULL
Node listFindValue(List list, int value) {
    Node p;
    for (p = list->head; p; p = p->next) {
        if (p->value == value) {
            return p;
        }
    }
    return NULL;
}

// 算长度
int listLength(List list) {
    int length = 0;
    Node p;
    for (p = list->head; p; p = p->next) {
        length++;
    }
    return length;

}

// 后面增加
void listAdd(List list, int value) {
    Node p = (Node)malloc(sizeof(*p));
    p->next = NULL;
    p->value = value;
    Node last = listFindLast(list);
    if (!last) {
        list->head = p;
    } else {
        last->next = p;
    }
}

// 中间增加，比如说在某个值的位置后面加一个节点
void listAddInner(List list, int value, int newValue) {
    Node p, q;
    p = listFindValue(list, value);
    q = (Node)malloc(sizeof(_Node));
    q->value = newValue;
    q->next = p->next;
    p->next = q;
}

// 删除指定数据所在的节点
void listDelete(List list, int member) {
    Node p, q;
    if (list->head->value == member) {
        p = list->head;
        list->head = p->next;
        free(p);
        p = NULL;
    } else {
        for (p = list->head; p; p = p->next) {
            if (p->next->value == member) {
                q = p->next;
                p->next = p->next->next;
                free(q);
                q = NULL;
                break;
            }
        }
    }
}

// 查找是否存在
int listFindNodeInner(List list, int value) {
    Node p;
    int flag = 0;
    for (p = list->head; p; p = p->next) {
        if (p->value == value) {
            flag = 1;
            break;
        }
    }
    return flag;
}

// 遍历打印
int listPrinter(List list) {
    Node p;
    for (p = list->head; p; p = p->next) {
        printf("%d\t", p->value);
    }
    printf("\n");
}

// 释放掉所有节点的内存
void listEnd(List list) {
    Node p, q;
    if (list->head) {
        for (p = list->head; p; p = q) {
            q = p->next;
            free(p);
        }
    }
}
