#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *array;
	int size;
	int length;
} *Array;

const int _BLOCK = 5;

// 初始化
Array arrayInit() {
	Array array;
	array->array = (int*)malloc(_BLOCK * sizeof(int));
	array->size = _BLOCK;
	array->length = _BLOCK;
	int i;
	printf("please input number, count 5\n");
	for (i = 0; i < _BLOCK; i++) {
		scanf("%d", &array->array[i]);
	}
	return array;
}

// 判断 member 是否存在
int memberOfArray(Array array, int member) {
	int i;
	for (i = 0; i < array->size; i++) {
		if (array->array[i] == member) {
			return 1;
		}
	}
}

// 判断这个 index 是否存在
int indexInArray(Array array, int index) {
	return index < array->size && index >= 0;
}

// 返回长度
int arrayLength(Array array) {
	return array->size;
}

// 返回第一个
int arrayFirst(Array array) {
	return array->array[0];
}

// 返回最后一个
int arrayLast(Array array) {
	return array->array[array->size - 1];
}

// 增长
void arrayIncrease(Array array, int newLength) {
	// 弄个新的长度的数组，复制过去
	int *newArray = (int*)malloc(newLength * sizeof(int));
	int i;
	for (i = 0; i < newLength; i++) {
		newArray[i] = 0;
		if (i < array->size) {
			newArray[i] = array->array[i];
		}
	}
	free(array->array);
	array->array = newArray;
	array->length = newLength;
}

// 判断长度够不够并作出相对应的操作
void arrayLengthChecker(Array array, int index) {
	if (index > array->size - 1) {
		if (index > array->length - 1) {
			int newLength = (index / _BLOCK + 1) * _BLOCK;
			arrayIncrease(array, newLength);
		}
		array->size = index + 1;
	}
}

// 返回指定 index 的
int indexOfArray(Array array, int index) {
	if (index < array->size && index >= 0) {
		return array->array[index];
	}
	perror("this index is out of array");
}

// 给指定 index 位置设定值，如果超过长度自动增长
int setValueToArray(Array array, int index, int value) {
	// 判断长度够不够
	arrayLengthChecker(array, index);
	array->array[index] = value;
}

// 直接打印数组
int printArray(Array array) {
	int i;
	for (i = 0; i < array->size; i++) {
		printf("%d\t", array->array[i]);
	}
	printf("\n");
}

// pop，抛出最后一个
int arrayPop(Array array) {
	int value = arrayLast(array);
	array->size--;
	array->array[array->size] = 0;
	return value;
}

// push，再后面加一个
void arrayPush(Array array, int value) {
	arrayLengthChecker(array, array->size);
	array->array[array->size - 1] = value;
}

// shift，前面删一个
int arrayShift(Array array) {
	int value = arrayFirst(array), i;
	for (i = 0; i < array->size - 1; i++) {
		array->array[i] = array->array[i + 1];
	}
	array->size--;
	return value;
}

// unshift，前面添一个
void arrayUnshift(Array array, int value) {
	arrayLengthChecker(array, array->size);
	int i;
	for (i = array->size - 1; i > 0; i--) {
		array->array[i] = array->array[i - 1];
	}
	array->array[0] = value;
}
