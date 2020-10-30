#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
	int coefficient, exponent;
	struct polynomial *next;
} *Polynomial;

typedef struct polynomialList {
	Polynomial first;
} *PolynomialList;

PolynomialList createPolynomialList();
int isEmpty(PolynomialList pList);
Polynomial polynomialListLastNode(PolynomialList pList);
void polynomialListAdd(PolynomialList pList, int coef, int expo);
void polynomialListPrinter(PolynomialList pList);
PolynomialList polynomialListSum(PolynomialList pList1, PolynomialList pList2);
void polynomialListEnd(PolynomialList pList);

int main() {
	PolynomialList pList = createPolynomialList();
	PolynomialList pList1 = createPolynomialList();
	PolynomialList pList2;

	polynomialListAdd(pList, 10, 5);
	polynomialListAdd(pList, 10, 4);
	// polynomialListPrinter(pList);
	polynomialListAdd(pList, 10, 6);
	polynomialListAdd(pList, 10, 1);
	// polynomialListPrinter(pList);
	polynomialListAdd(pList1, 10, 6);
	// polynomialListPrinter(pList);
	polynomialListAdd(pList1, 10, 3);
	// polynomialListPrinter(pList);
	polynomialListAdd(pList1, 10, 2);
	// polynomialListPrinter(pList);
	polynomialListAdd(pList1, -10, 1);
	// polynomialListPrinter(pList);
	pList2 = polynomialListSum(pList, pList1);
	printf("\n");
	polynomialListPrinter(pList);
	polynomialListPrinter(pList1);
	polynomialListPrinter(pList2);

	polynomialListEnd(pList);
	pList = NULL;
	polynomialListEnd(pList1);
	pList1 = NULL;
	polynomialListEnd(pList2);
	pList2 = NULL;

	return 0;
}

// 初始化一个多项式列表，返回其指针
PolynomialList createPolynomialList() {
	PolynomialList pList = (PolynomialList)malloc(sizeof(struct polynomialList));
	pList->first = NULL;
	return pList;
}

// 判断多项式列表是否为空
int isEmpty(PolynomialList pList) {
	return pList->first == NULL;
}

// 找最后一个节点，返回那个节点的指针
Polynomial polynomialListLastNode(PolynomialList pList) {
	Polynomial p = pList->first;
	if (!isEmpty(pList)) {
		while (p->next) {
			p = p->next;
		}
	}
	return p;
}

// 根据指数找到那个指数节点的指针，找不到则返回NULL
Polynomial polynomialFindByExponent(PolynomialList pList, int expo) {
	Polynomial p;
	for (p = pList->first; p; p = p->next) {
		if (p->exponent == expo) {
			break;
		}
	}
	return p;
}

// 多项式增加,指数大的放在前面
void polynomialListAdd(PolynomialList pList, int coef, int expo) {
	Polynomial q1, q2, q3;
	// 创建新的 Polynomial 指针
	Polynomial p = (Polynomial)malloc(sizeof(struct polynomial));
	p->coefficient = coef;
	p->exponent = expo;
	p->next = NULL;

	if (isEmpty(pList)) { // 如果是空的
		pList->first = p;
		p->next = NULL;
	} else { // 不是空的
		q1 = polynomialFindByExponent(pList, expo);
		if (q1) { // 如果找到了指数相同的
			q1->coefficient += coef;
			free(p);
			p = NULL;
		} else {
			q1 = pList->first; // 第一个节点
			q2 = polynomialListLastNode(pList); // 最后一个节点
			if (expo > q1->exponent) { // 指数比第一个节点的指数都大，说明肯定是放在最前面的
				p->next = q1;
				pList->first = p;
			} else if (expo < q2->exponent) { // 指数比最后一个还要小，就放在最后
				q2->next = p;
			} else { // 指数在最大和最小之间的情况
				for (q3 = q1->next; q3; q1 = q1->next, q3 = q3->next) {
					if ((q1->exponent > expo) && (q3->exponent < expo)) {
						p->next = q3;
						q1->next = p;
						break;
					}
				}
			}
		}
	}
}

// 打印多项式
void polynomialListPrinter(PolynomialList pList) {
	Polynomial p;
	for (p = pList->first; p; p = p->next) {
		if (p->coefficient) {
			printf("%dx%d\t", p->coefficient, p->exponent);
		}
	}
	printf("\n");
}

// 多项式相加
PolynomialList polynomialListSum(PolynomialList pList1, PolynomialList pList2) {
	PolynomialList resultList = createPolynomialList();
	Polynomial p1, p2, p3;
	p1 = pList1->first;
	p2 = pList2->first;
	p3 = NULL;
	while (p1 && p2) { // 结束后至少有一个是NULL了，也有可能两个都是NULL
		if (p1->exponent > p2->exponent) {
			polynomialListAdd(resultList, p1->coefficient, p1->exponent);
			p1 = p1->next;
			printf("large");
		} else if (p1->exponent < p2->exponent) {
			polynomialListAdd(resultList, p2->coefficient, p2->exponent);
			p2 = p2->next;
			printf("little");
		} else {
			polynomialListAdd(resultList, p1->coefficient + p2->coefficient, p1->exponent);
			p1 = p1->next;
			p2 = p2->next;
			printf("=");
		}
	}

	if (p1 || p2) { // 能进去说明至少有一个还没结束
		p3 = p2;
		if (p1) { // 如果 p1 不是 NULL， p3取到p1的地址
			p3 = p1;
		}
	}

	while (p3) {
		polynomialListAdd(resultList, p3->coefficient, p3->exponent);
		p3 = p3->next;
	}

	return resultList;
}

// 释放多项式所有节点以及多项式的内存
void polynomialListEnd(PolynomialList pList) {
	Polynomial p, q;
	for (p = pList->first; q; p = q) {
		q = p->next;
		free(p);
	}
	p = q = NULL;
	free(pList);
}
