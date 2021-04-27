#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//野指针
//概念：野指针就是指针指向的位置是不可知的(随机的,不正确的,没有明确限制的)

//野指针的成因
//1.指针未初始化
int main()
{
	int*p;//局部变量指针未初始化,默认为随机值,导致地址也是随机的
	*p = 20;
	return 0;
}


//2.指针越界访问
int main()
{
	int arr[10] = { 0 };
	int*p = arr;
	int i = 0;
	for (i = 0; i < 12; i++)
	{
		//当指针指向的范围超出数组arr的范围时,p就是野指针
		*(p++) = i;
		//*p = i;
		//p++;
	}
	return 0;
}

//3.指针指向空间释放
int*test()
{
	int a = 10;  //脱离函数test()时,a所占的内存空间释放,临时空间消失
	return &a;
}
int main()
{
	int* p = test();  //记住临时变量的地址无意义
	*p = 20;  //再通过*p所知的地址去找内存,此处指向了一块已经被释放的内存块
	return 0;
}

//如何规避野指针
//1.指针初始化  2.小心指针越界  3.指针指向空间释放即使置NULL  4.指针使用之前检查有效性

int main()
{
	int a = 10;
	int*pa = &a;
	int* p = NULL; //空指针,用于指针不引用有效对象,但此时的指针已经进行了初始化,并给指针赋空值
	return 0;
}

