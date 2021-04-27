#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//二级指针
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;  //二级指针
	//int*** pppa = &ppa;  //三级指针
	printf("%d\n", **ppa);  //打印出的是a的内容
	return 0;
}


//指针数组 - 数组（存放指针的数组）  
//（区分另一个概念为数组指针 - 指针）
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	//多个指针存放的时候很麻烦
	//所以就有了指针数组(存放指针)
	int* arr[3] = { &a,&b,&c };  //指针数组
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ",*(arr[i]));
	}
	return 0;
}