#include<stdio.h>
#include<assert.h>
//һ�������ַ��������ĺ�����ʵ�ֺ��Ż���

//my_1_strcopy�Ѿ�����ʵ�ֿ������ܵ����������⣺
/*
1.���벻����ࡣ
2.���������ǿ��ǲ�ȫ��
3.Դ�ַ���y���иı�ķ��ա�
*/
void my_1_strcopy(char* x,char* y)
{
	while (*y != '\0')
	{
		*x = *y;
		x++;
		y++;
	}
	*x = *y;
}

/*
1.�Դ��볤�Ƚ����Ż�����Ч���˴��롣
2.����Ľ� {*x=*y; �򻯽���while��*x++ = *y++����
			x++;
			y++;}
			*x=*y;
*/
void my_2_strcopy(char* x, char* y)
{
	while (*x++ = *y++)
	{
		;
	}
}

/*
1.�Դ�����Ч�ʹ��δ�����Ż���
2.��ֹ�˿�ָ���Σ�ա�
*/
void my_3_strcopy(char* x, char* y)
{
	if (x != NULL && y != NULL)
	{
		while (*x++ = *y++)
		{
			;
		}
	}
	else
	{
		printf("�������γ����ˣ���");
	}
	
}
/*
1.ͨ���������if�жϸ�����Ч��
*/
void my_5_strcopy(char* x, char* y)
{
	assert(x != NULL);//����
	assert(y != NULL);
	while (*x++ = *y++)
	{
		;
	}
}

//1.ͨ��const��Դ�ַ���y���б�����
//  ��ֹ*y��ֵ�����ı䡣
void my_6_strcopy(char* x, const char* y)
{
	assert(x != NULL);//����
	assert(y != NULL);
	while (*x++ = *y++)
	{
		;
	}
}

int main()
{
	char a[] = "abcdefj";
	char b[] = "����";
	my_2_strcopy(a, b);
	printf("%s", a);
}