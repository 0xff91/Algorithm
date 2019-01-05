# c&c++ 语法基础

> 需要重新整理一下

> c c++中一类的内容整理到一块


> 练习算法，主要是算法思想，怎么容易实现怎么来
>
> 混合c++与c无所谓，主要是算法思想
>
> 在具体项目中才要学会c c++的一些特性技巧
> 
> 下面主要是记录自己需要的一些东西

## 常用函数

 1. memset
    头文件： string.h
    原型：
        void *memset(void *s, int c, size_t n);
 2. memcpy
    头文件： string.h
    原型：
        void *memcpy(void *dest, const void *src, size_t n);

## 排序

### qsort
头文件：stdlib.h

函数原型：

```c
void qsort(
        void *base,
        size_t nmemb,
        size_t size,
        int (*compar)(const void *, const void *)
    );
```
如果compar返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的前面
如果compar返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定
如果compar返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的后面

注意qsort的cmpar函数，p1与p2的地址是在base基础上加上一个指定的数字之后传入的，所以p1与p2不是数组中的元素的类型，而是数组中元素的地址


## 变量

## 输入输出

### scanf，getchar

1. 输入数字

```c
scanf("%d%d%d", &a, &b, &c); 
```


以空格或者换行作为分隔符

```shell
1 2 3
```

2. 输入字符

```c
scanf("%c%c%c", &a, &b, &c);
```

所有都是字符，**包括空格 回车**

3. 输入字符串

```c
char a[5];
scanf("%s", a);
```

以空格与回车作为分隔符



在执行完scanf之后，stdin缓冲区中一般还有一个回车，应该使用getchar或者fflush(stdin)清除掉，如果下次需要读取一个字符或者字符串的话，读取数字则无所谓了。  


### gets, puts

读取或者输出一行字符串，以换行\n作为分隔符，因此，使用gets之前应清空输入缓冲区，默认在读入的字符串后面加一个'\0'。

### sscanf, sprintf

```c
sscanf(screen, "%d", &n);
sprintf(screen, "%d", &n);
```

可以使用__**正则表达式**__

### string.h

1. strlen

获取字符串长度，到'\0'之前的字符的个数，不包括'\0'

```c
char c[10];
sizeof(c); 	// 获取数组c的大小 10, sizeof以字节为单位
			// 但是数组名在作为函数参数时退化为指针，sizeof只能获取到指针的大小
```

### 数组

数组名不是指针，但有时候会退化为指针

数组传参

```c
// 一维数组
int func(int *a);

// 二维数组
int func(int a[][3]);
int func(int (*a)[3]);
int func(int **a);
```



### 指针

指针作为函数参数，其实也是一个副本，对指针这个数的操作不会影响调用它的函数中原有指针数的变化。

```c
// a, b仅仅是副本
int swap(int *a, int *b) {
	int *tmp = a;
    a = b;
    b = tmp;
}

int main() {
	int d1 = 0;
    int d2 = 1;
    int *a = &d1;
    int *b = &d2;
    
    swap(a, b);
    // 实际上a，b没有变化
}
```

### stl

