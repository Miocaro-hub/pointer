#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����ָ��
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;  //����ָ��
	//int*** pppa = &ppa;  //����ָ��
	printf("%d\n", **ppa);  //��ӡ������a������
	return 0;
}


//ָ������ - ���飨���ָ������飩  
//��������һ������Ϊ����ָ�� - ָ�룩
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int* pa = &a;
	int* pb = &b;
	int* pc = &c;
	//���ָ���ŵ�ʱ����鷳
	//���Ծ�����ָ������(���ָ��)
	int* arr[3] = { &a,&b,&c };  //ָ������
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ",*(arr[i]));
	}
	return 0;
}