#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		printf("%d\n", i);
		arr[i] = 0;
	}
	return 0;
}
//结果为啥为死循环？

/*
  注：栈区的默认使用为：
	  先用高地址空间
	  再用低地址空间
  
  注：数组随着下标增长
	    地址由低到高
*/
