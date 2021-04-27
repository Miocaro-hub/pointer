#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//指针运算
//指针+ -整数  指针-指针   指针的关系运算

//指针+ - 整数
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int*p = arr;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *p);
		p = p + 1; //p++
	}
	return 0;
}

//指针 - 指针
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,11 };
	printf("%d\n", &arr[9] - &arr[0]);  //这里面两个指针相减得到的是指针指向两个数组之间的元素个数

	char ch[5] = { 0 };
	printf("%d\n", &arr[9] - &ch[0]);  //error 两个指针相减一定要指向同一个空间
	return 0;
}


int my_strlen(char* str)
{
	char* start = str;  //指向首元素
	char* end = str;
	while (*end != '\0')
	{
		end++;  //希望*end指向的元素为\0
	}
	return end - start;  //得到的就是字符串的长度
}
int main()
{
	//strlen - 求字符串长度
	char arr[] = "bit";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//指针的关系运算
#define N_VALUES 5
int main()
{
	float values[N_VALUES];
	float *vp;
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;
	}

	//可简化为
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
		*vp = 0;
	return 0;
	//实际上在绝大部分的编译器上是可以顺利完成任务的,然而我们还是应该避免第二种写法,因为标准并不保证它可行
	//标准规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较,但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
}


//指针和数组
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);  //打印出的地址一致,可见数组的地址就是首元素的地址
	//1. &arr - &数组名 - 数组名不是首元素的地址 - 数组名表示整个数组 - &数组名 取出的是整个数组的地址
	//2. sizeof(arr) - sizeof(数组名) - 数组名不是首元素地址 - 数组名表示整个数组 - sizeof(数组名)计算的是整个数组的大小
	
	printf("p\n", &arr);  //虽然打印的地址结果和上面两个相同,但确实整个数组的地址
	
	printf("%p\n", arr+1);  //+4个字节
	printf("%p\n", &arr[0]+1);  //+4个字节
	printf("p\n", &arr+1);  //+40个字节
	return 0;
}


int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		pinrtf("%p  ---------  %p\n", p + i, &arr[i]);  //通过这个打印结果可以说明指针p存放的每个元素的地址和从数组中取出的每个元素的地址是完全一致的
	}

	//可简化为
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);  //printf("%d ", *(p+i));
	}
	return 0;
}
