//必须用两个函数来判断，同一个函数里变量的声明顺序和在栈里的顺序可能不一致。

#include <stdio.h>
#include <iostream>
using namespace std;

void f(int *a)
{
	int b = 1;
	printf("%p %p\n", a, &b);
}

int main()
{
	int a = 0;
	f(&a);
	return 0;
}
