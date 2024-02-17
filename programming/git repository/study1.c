#include<stdio.h>
#include<assert.h>
//一个关于字符串拷贝的函数的实现和优化。

//my_1_strcopy已经初步实现拷贝功能但有如下问题：
/*
1.代码不够简洁。
2.参数传递是考虑不全。
3.源字符串y会有改变的风险。
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
1.对代码长度进行优化，有效简化了代码。
2.巧妙的将 {*x=*y; 简化进入while（*x++ = *y++）。
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
1.对传参无效和传参错误的优化。
2.防止了空指针的危险。
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
		printf("！！传参出错了！！");
	}
	
}
/*
1.通过断言替代if判断更加有效。
*/
void my_5_strcopy(char* x, char* y)
{
	assert(x != NULL);//断言
	assert(y != NULL);
	while (*x++ = *y++)
	{
		;
	}
}

//1.通过const对源字符串y进行保护，
//  防止*y的值发生改变。
void my_6_strcopy(char* x, const char* y)
{
	assert(x != NULL);//断言
	assert(y != NULL);
	while (*x++ = *y++)
	{
		;
	}
}

int main()
{
	char a[] = "abcdefj";
	char b[] = "惊蛰";
	my_2_strcopy(a, b);
	printf("%s", a);
}