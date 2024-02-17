# 数据结构之链表实现

## 1、data.h(头文件)

```c

#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<math.h>

#pragma once
#define N 1000

typedef int SLD;

typedef struct SListNode
{
	SLD data;
	struct SListNode* next;
}SLNode;

//头节点初始化
void lnitList_L(SLNode** pphead);

//输出函数print
void SList_print(SLNode* phead);

//尾部插入数据
void SList_push_back(SLNode** pphead, SLD x);

//尾插法数据录入
void SList_Create_end(SLNode** pphead, int n);

//头部插入数据
void SList_push_front(SLNode** pphead, int x);

//头插法数据录入
void SList_Create_head(SLNode** pphead, int n);

//求链表长度
int SList_len(SLNode** pphead);

//从单链表中取第i个元素
SLD SList_git_i(SLNode** pphead, int i);

//查找为e值的元素所在位置
SLD SList_e_seat(SLNode** pphead, SLD e);

```



## 2、SeqList.c（函数文件）

```c
#include"SeqL.h"


//初始化头节点
void lnitList_L(SLNode** pphead)
{
	SLNode*newhead = (SLNode*)malloc(sizeof(SLNode));
	newhead->next = NULL;
	*pphead = newhead;
}


//创建new结点
SLNode* Buy_list_node(SLNode* x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}


//输出函数
void SList_print(SLNode* phead)
{
	SLNode* cur = phead->next;
	while (cur != NULL)
	{
		printf("%d,", cur->data);
		cur = cur->next;
	}
}


//头部插入数据
void SList_push_front(SLNode** pphead, int x)
{
	SLNode* newnode = Buy_list_node(x);
	newnode->next = (*pphead)->next;
	(*pphead)->next = newnode;
}


//数据录入(头插法)
void SList_Create_head(SLNode** pphead,int n)
{
	printf(">>头部录入%d组数据<<\n",n);
	if (*pphead == NULL)
	{
		SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
		newnode->next = NULL;
		*pphead = newnode;
	}
	else
	{
		int i = 0;
		for (i = n; i > 0; --i)
		{
			SLNode* node = (SLNode*)malloc(sizeof(SLNode));
			printf("请输入需要录入的数值：");
			scanf("%d", &node->data);
			node->next = (*pphead)->next;
			(*pphead)->next = node;
		}
	}
}


//尾部插入数据
void SList_push_back(SLNode** pphead, SLD x)
{
	SLNode* newnode = Buy_list_node(x);
	//可用于检测*pphead是否为NULL，如果是NULL则报错。
	//assert(*pphead != NULL);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾结点
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//录入数据（尾插法）
void SList_Create_end(SLNode** pphead, int n)
{
	printf(">>尾部录入%d组数据<<\n",n);
	if (*pphead == NULL)
	{
		SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
		newnode->next = NULL;
		*pphead = newnode;
	}
	else
	{
		int i = 0;
		SLNode* e = *pphead;
		for (i = n; i > 0; --i)
		{
			SLNode* node = (SLNode*)malloc(sizeof(SLNode));
			printf("请输入需要录入的数值：");
			scanf("%d", &node->data);
			node->next = NULL;
			e->next = node;
			e = node;
		}
	}
}


//求链表长度
int SList_len(SLNode** pphead)
{
	SLNode* p = (*pphead)->next;
	int i = 0;
	while (p != NULL)
	{
		++i;
		p = p->next;
	}
	return i;
}


//从单链表中取第i个元素
SLD SList_git_i(SLNode** pphead, SLD i)
{
	//判断i是否越界
	if (i > SList_len(pphead))return -1;

	int j = 1, e = 0;
	SLNode* p = (*pphead)->next;

	//head 1 2 3 4 5 （i=3）
	while (j <= i && p != NULL)
	{
		p = p->next;
		++j;
	}
	//p
	if (p == NULL || j > i)return 0;
	e = p->data;
	return e;
}


//查找为e值的元素所在位置
SLD SList_e_seat(SLNode** pphead, SLD e)
{
	int i = 1;
	int len = SList_len(pphead);
	SLNode* p = (*pphead)->next;
	while (p->data != e)
	{
		p = p->next;
		++i;
		if (p == NULL)break;
	}
	if (p == NULL || i > len) return -1;

	return i;
}
```



## 3、Text.c（测试文件）

```c


#include"SeqL.h"

void TestSList1()
{
	//由于plist为指针，故要传plist的地址，也就是&plist
	SLNode* plist = NULL;
	
	//头节点初始化
	lnitList_L(&plist);
	
	//SList_Create_end(&plist, 6);
	
	//SList_Create_h(&plist, 6);

	//尾部插入数据
	SList_push_back(&plist, 1);
	SList_push_back(&plist, 2);
	SList_push_back(&plist, 3);
	SList_push_back(&plist, 4);
	SList_push_back(&plist, 5);

	//录入数据（尾插法）
	//SList_Create_end(&plist, 3);
	

	//数据录入(头插法)
	//SList_Create_head(&plist, 3);


	//头部插入数据
	//SList_push_front(&plist, 66);

	//求链表长度
	int len = 0;
	len = SList_len(&plist);
	printf("%d\n", len);

	//获取第i个元素
	int x = SList_git_i(&plist,6);
	printf("%d\n", x);

	//查找为e值的元素所在位置
	int i = SList_e_seat(&plist, 9);
	printf("%d\n", i);

	//输出函数
	SList_print(plist);
}

int main()
{
	TestSList1();
    return 0;
}
```

