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

 3. qsort
    头文件：stdlib.h
    原型：
    ```c
      void qsort(
              void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *)
          );
    ```
    说明：
      如果compar返回值小于0（< 0），那么p1所指向元素会被排在p2所指向元素的前面
      如果compar返回值等于0（= 0），那么p1所指向元素与p2所指向元素的顺序不确定
      如果compar返回值大于0（> 0），那么p1所指向元素会被排在p2所指向元素的后面

      注意qsort的cmpar函数，p1与p2的地址是在base基础上加上一个指定的数字之后传入的，所以p1与p2（不是\*p2，\*p2表示p2所指的一个字节）不是数组中的元素的类型，而是数组中元素的首地址，因此我们需要先把他们转换成数组中元素类型的指针(type *)p1，然后在取数组中元素((type *)p1)->...

 4. 数学函数：
    头文件： math.h
    包含：
     1. 三角函数：
       ```c
       double sin/cos/tan(double)   
       ```
     2. 反三角函数：
       ```c
        double asin/acos/atan(double)
        double atan2(double, double)
       ```
     3. 双曲三角函数
       ```c
        double sinh (double);
        double cosh (double);
        double tanh (double);
       ```
     4. 指数与对数
       ```c
        double frexp(double value,int *exp);这是一个将value值拆分成小数部分f和（以2为底的）指数部分exp，并返回小数部分f，即f*2^exp。其中f取值在0.5~1.0范围或者0。
        double ldexp(double x,int exp);这个函数刚好跟上面那个frexp函数功能相反，它的返回值是x*2^exp
        double modf(double value,double *iptr);拆分value值，返回它的小数部分，iptr指向整数部分。
        double log (double); 以e为底的对数
        double log10 (double);以10为底的对数
        double pow(double x,double y);计算x的y次幂
        float powf(float x,float y); 功能与pow一致，只是输入与输出皆为单精度浮点数
        double exp (double);求取自然数e的幂
        double sqrt (double);开平方根
       ```

     5. 取整
       ```c
        double ceil (double); 取上整，返回不比x小的最小整数
        double floor (double); 取下整，返回不比x大的最大整数，即高斯函数[x]
       ```

     6. 绝对值
       ```c
        int abs(int i); 求整型的绝对值
        double fabs (double);求实型的绝对值
        double cabs(struct complex znum);求复数的绝对值
       ```
     7. 标准化浮点数
       ```c
        double frexp (double f,int *p); 标准化浮点数，f = x * 2^p，已知f求x,p (x介于[0.5,1])
        double ldexp (double x,int p); 与frexp相反，已知x,p求f
       ```

     8. 取整与取余
       ```c
        double modf (double,double*); 将参数的整数部分通过指针回传，返回小数部分
        double fmod (double,double); 返回两参数相除的余数
       ```
     9. 其他
       ```c
        double hypot(double x,double y);已知直角三角形两个直角边长度，求斜边长度
        double ldexp(double x,int exponent);计算x*（2的指数幂）
        double poly(double x,int degree,double coeffs []);计算多项式
        int matherr(struct exception *e);数学错误计算处理程序
       ```

## 常用头文件

 1. math.h (c)
    double sin(double)
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

注意qsort的cmpar函数，p1与p2的地址是在base基础上加上一个指定的数字之后传入的，所以p1与p2（不是\*p2，\*p2表示p2所指的一个字节）不是数组中的元素的类型，而是数组中元素的首地址，因此我们需要先把他们转换成数组中元素类型的指针(type *)p1，然后在取数组中元素((type *)p1)->...


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

