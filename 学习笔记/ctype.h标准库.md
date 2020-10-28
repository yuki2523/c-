## ctype.h标准库

```c
	// 准备
	int ch1 = 'd';
	char ch2 = '2';
	int ch3 = '\t';
	int ch4 = 'e';
	char ch5 = 'f';
	char ch6 = ' ';
	char ch7 = '\n';
	int ch8 = '3';
	char ch9 = 'D';
	char ch10 = ',';
	char ch11 = '/';
```

### 1、isalnum() 是否是数字或字母，int:4, char:2, 不是数字或字母:0

```c
	printf("%d\n", isalnum(ch1)); // 2
	printf("%d\n", isalnum(ch2)); // 4
	printf("%d\n", isalnum(ch3)); // 0
	printf("%d\n", isalnum(ch4)); // 2
	printf("%d\n", isalnum(ch5)); // 2
	printf("%d\n", isalnum(ch6)); // 0
```

### 2、isalpha() 是否是字母，字母:2，不分int和char，非字母:0

```c
	printf("%d\n", isalpha(ch1)); // 2
	printf("%d\n", isalnum(ch5)); // 2
	printf("%d\n", isalpha(ch2)); // 0
```

### 3、iscntrl() 是否是控制字符,比如 \t,\n 这类的:32,否则为:0

```c
	printf("%d\n", iscntrl(ch1)); // 0
	printf("%d\n", iscntrl(ch3)); // 32
	printf("%d\n", iscntrl(ch7)); // 32
```

### 4、isdigit() 是否是十进制数，数字:1, 字母:0, 别的字符:0

```c
	printf("%d\n", isdigit(ch2)); // 1
	printf("%d\n", isdigit(ch8)); // 1
	printf("%d\n", isdigit(ch1)); // 0
	printf("%d\n", isdigit(ch3)); // 0
```

### 5、islower() 是否是小写，大写：0，小写：2，不是字母：0

```c
	printf("%d\n", islower(ch1)); // 2
	printf("%d\n", islower(ch9)); // 0
	printf("%d\n", islower(ch2)); // 0
```

### 6、ispunct() 是否是标点符号，',': 16 ,'/': 16, ' ': 0

```c
	printf("%d\n", ispunct(ch10)); // 16
	printf("%d\n", ispunct(ch11)); // 16
	printf("%d\n", ispunct(ch6)); // 0
```

### 7、isspace() 是否是空格，空格: 8,非空格:0

```c
	printf("%d\n", isspace(ch6)); // 8
	printf("%d\n", isspace(ch8)); // 0
	printf("%d\n", isspace(ch3)); // 8
	/*
		空格包括：
			' '     (0x20)    space (SPC) 空格符
			'\t'    (0x09)    horizontal tab (TAB) 水平制表符
			'\n'    (0x0a)    newline (LF) 换行符
			'\v'    (0x0b)    vertical tab (VT) 垂直制表符
			'\f'    (0x0c)    feed (FF) 换页符
			'\r'    (0x0d)    carriage return (CR) 回车符
	*/
```

### 8、issupper() 是否是大写，大写：1，小写：0，非字母：0

```c
	printf("%d\n", isupper(ch1)); // 0
	printf("%d\n", isupper(ch9)); // 1
	printf("%d\n", isupper(ch10)); // 0
```

### 9、isxdigit() 是否为16进制数，返回：128,否则为0

```c
	printf("%d\n", isxdigit(ch1)); // 128
	printf("%d\n", isxdigit(ch2)); // 128
	printf("%d\n", isxdigit(ch3)); // 0
```

### 10、tolower()和toupper(),可以把大写换成小写，小写换成大写

```c
	printf("%c\n", tolower('A')); // a
	printf("%c\n", toupper('a')); // A
```

