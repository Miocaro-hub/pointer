#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//ָ������
//ָ��+ -����  ָ��-ָ��   ָ��Ĺ�ϵ����

//ָ��+ - ����
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

//ָ�� - ָ��
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,11 };
	printf("%d\n", &arr[9] - &arr[0]);  //����������ָ������õ�����ָ��ָ����������֮���Ԫ�ظ���

	char ch[5] = { 0 };
	printf("%d\n", &arr[9] - &ch[0]);  //error ����ָ�����һ��Ҫָ��ͬһ���ռ�
	return 0;
}


int my_strlen(char* str)
{
	char* start = str;  //ָ����Ԫ��
	char* end = str;
	while (*end != '\0')
	{
		end++;  //ϣ��*endָ���Ԫ��Ϊ\0
	}
	return end - start;  //�õ��ľ����ַ����ĳ���
}
int main()
{
	//strlen - ���ַ�������
	char arr[] = "bit";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}

//ָ��Ĺ�ϵ����
#define N_VALUES 5
int main()
{
	float values[N_VALUES];
	float *vp;
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;
	}

	//�ɼ�Ϊ
	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
		*vp = 0;
	return 0;
	//ʵ�����ھ��󲿷ֵı��������ǿ���˳����������,Ȼ�����ǻ���Ӧ�ñ���ڶ���д��,��Ϊ��׼������֤������
	//��׼�涨������ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ��Ƚ�,���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�
}


//ָ�������
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);  //��ӡ���ĵ�ַһ��,�ɼ�����ĵ�ַ������Ԫ�صĵ�ַ
	//1. &arr - &������ - ������������Ԫ�صĵ�ַ - ��������ʾ�������� - &������ ȡ��������������ĵ�ַ
	//2. sizeof(arr) - sizeof(������) - ������������Ԫ�ص�ַ - ��������ʾ�������� - sizeof(������)���������������Ĵ�С
	
	printf("p\n", &arr);  //��Ȼ��ӡ�ĵ�ַ���������������ͬ,��ȷʵ��������ĵ�ַ
	
	printf("%p\n", arr+1);  //+4���ֽ�
	printf("%p\n", &arr[0]+1);  //+4���ֽ�
	printf("p\n", &arr+1);  //+40���ֽ�
	return 0;
}


int main()
{
	int arr[10] = { 0 };
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		pinrtf("%p  ---------  %p\n", p + i, &arr[i]);  //ͨ�������ӡ�������˵��ָ��p��ŵ�ÿ��Ԫ�صĵ�ַ�ʹ�������ȡ����ÿ��Ԫ�صĵ�ַ����ȫһ�µ�
	}

	//�ɼ�Ϊ
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
