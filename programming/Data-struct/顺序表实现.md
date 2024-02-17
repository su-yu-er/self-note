# 数据结构之顺序表实现

## 1、data.h(头文件)

```c
//动态顺序表的实现
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#pragma once
#define N 1000

typedef int SLD;

//动态顺序表
typedef struct SeqList
{
	SLD* a;		//嵌套定义a空间
	int size;		//数据大小
	int capacity;	//空间大小
}SL;


//初始化结点
void SeqListInit(SL* ps);

//数据录入
void Data_entry(SL* ps);

//空间扩容
void SeqListCheckCapacity(SL* ps);

//空间释放
void SeqListDestory(SL* ps);

//尾插法
void SeqListPushBack(SL* ps, SLD x);

//尾删法
void SeqListPopBack(SL* ps);

//头插法
void SeqListPushFront(SL* ps, SLD x);

//头删法
void SeqListPopFront(SL* ps);

//指定位置插入元素
int SeqList_Insert(SL* ps, int i, SLD e);

//输出函数
void print(SL* ps);

//排序函数
void Seq_sort(SL* ps);

```



## 2、SeqList.c(函数文件)

```c

#include"data.h"


//初始化结点
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//空间释放（当用完顺序表后防止野指针）
void SeqListDestory(SL* ps)
{
	//free函数只是将ps->a申请的空间还回系统而ps->a依旧指向那块区域，
	//所以free后通常要将ps->a的值置为NULL。
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//空间扩容函数
void SeqListCheckCapacity(SL* ps)
{
	//空间不足够，扩容
	if (ps->size == ps->capacity)
	{
		//扩容一般扩2倍（较为合理）
		int newcapcity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLD* tmp = (SLD*)realloc(ps->a, newcapcity * sizeof(SLD));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);	//终止程序（不能用return）
		}
		ps->a = tmp;
		ps->capacity = newcapcity;
	}
}


//数据录入
void Data_entry(SL* ps)
{
	SeqListCheckCapacity(ps);

	int i = 0;
	SLD element = 0;
	printf("输入“-1”时输入结束\n");
	printf("请输入数据>>>\n");
	scanf("%d", &element);
	while (element != -1)
	{
		ps->a[i] = element;
		printf("请输入数据>>>\n");
		++i;
		++ps->size;
		scanf("%d", &element);
	}
}


//尾插法（在末尾插入数据）
void SeqListPushBack(SL* ps, SLD x)
{
	SeqListCheckCapacity(ps);
	//空间足够
	ps->a[ps->size] = x;
	++(ps->size);
}


//尾删（删除末尾的数据）
void SeqListPopBack(SL* ps)
{
	//将最后的数据置为0
	//ps->a[ps->size - 1] = 0;
	//断言检测size是否越界
	assert(ps->size > 0);
	--ps->size;
}


//头插（在顺序表表头插入）
void SeqListPushFront(SL* ps, SLD x)
{
	SeqListCheckCapacity(ps);
	int i = 0;
	for (i = ps->size - 1; i >= 0; --i)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	++ps->size;

}


//头删（在顺序表表头删去）
void SeqListPopFront(SL* ps)
{
	//判断ps是否为空
	assert(ps->size > 0);
	int i = 0;
	for (i = 1; i <= ps->size; ++i)
	{
		ps->a[i - 1] = ps->a[i];
	}
	--ps->size;
}


//输出函数
void print(SL* ps)
{
	assert(ps->size > 0);
	int i = 0;
	printf("顺序表数据如下:\n");
	for (i = 0; i < ps->size; ++i)
	{	
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}


//指定位置插入元素
int SeqList_Insert(SL* ps, int i, SLD e)
{
	assert(ps->size > 0);
	SeqListCheckCapacity(ps);

	//判断插入位置是否越界
	if (i<1 || i>ps->size)
	{
		printf("<<<插入位置越界>>>\n");
		return 0;
	}

	//判断插入数据是否重复
	int h = 0;
	for (h = 0; h < ps->size; ++h)
	{
		if (ps->a[h] == e)
		{
			printf("<<<插入数据重复>>>\n");
			return 0;
		}
	}

	int j = 0;
	for (j = ps->size - 1; j >= i - 1; --j)
	{
		ps->a[j + 1] = ps->a[j];
	}

	ps->a[i - 1] = e;
	++ps->size;
	return 1;
}


//数据排序（冒泡）
void Seq_sort(SL* ps)
{
	assert(ps->size > 0);

	int i = 0, j = 0;
	int x = 0;
	for (i = 0; i < ps->size-1; ++i)
	{
		int f = 0;
		for (j = 0; j < ps->size - i - 1; ++j)
		{
			//降序排列
			if (ps->a[j] > ps->a[j + 1])
			{
				x = ps->a[j + 1];
				ps->a[j + 1] = ps->a[j];
				ps->a[j] = x;
				f = 1;
			}
		}
		if (f == 0)break;
	}
}
```



## 3、Test.c(测试文件)

```c
#include"data.h"

void TestSeqList1()
{
	SL sl;
	int i = 0;

	SeqListInit(&sl);
	Data_entry(&sl);
	print(&sl);
	int loc = 0, e = 0;
	/*printf("请输入插入位置和元素>>>");
	scanf("%d%d", &loc, &e);
	SeqList_Insert(&sl,loc,e);*/
	Seq_sort(&sl);
	print(&sl);
}

int main()
{
	TestSeqList1();
	return 0;
}
```

