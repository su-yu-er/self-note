
#include"game1.h"
void menu()
{
	printf("**********************\n");
	printf("*****1.#����PLAY******\n");
	printf("**********************\n");
	printf("****2.#�������pk*****\n");
	printf("**********************\n");
	printf("****3.���������pk****\n");
	printf("**********************\n");
	printf("****0.�˳���ϷEXIT****\n");
	printf("**********************\n");
}
//��Ϸ1--�������˻�
void game1()
{
	char ret = 0;
	char board[ROW][COL] = {0};
	//��ʼ��(����)����
	InitBoard3(board, ROW, COL);
	printf("\n");
	//��ӡ����
	DisplayBoard3(board, ROW, COL);
	printf("\n");
	//�����ʵ��
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
        printf("\n");
		//�ж���Ӯ
		ret = Iswin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}

		//��������
		ComputerMove(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
		printf("\n");
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ����\n");
	}
	else if(ret == '#')
	{
		printf("����Ӯ����\n");
	}
	else
	{
		printf("   ��ƽ�֡�\n");
	}
}

//��Ϸ2--���������pk
void game2()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ��(����)����
	InitBoard3(board, ROW, COL);
	printf("\n");
	//��ӡ����
	DisplayBoard3(board, ROW, COL);
	printf("\n");
	//�����ʵ��
	while (1)
	{
		//���1����
		PlayerMove(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
		printf("\n");
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}

		//���2����
		Player2Move(board, ROW, COL);
		printf("\n");
		DisplayBoard3(board, ROW, COL);
		printf("\n");
		//�ж���Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���1Ӯ����\n");
	}
	else if (ret == '#')
	{
		printf("���2Ӯ����\n");
	}
	else
	{
		printf("   ��ƽ�֡�\n");
	}
}

//��Ϸ3--���������pk
void game3()
{
	char ret = 0;
	char board[FIVE_X][FIVE_Y] = { 0 };
	//��ʼ��(����)����
	InitBoard5(board, FIVE_X, FIVE_Y);
	printf("\n");
	//��ӡ����
	DisplayBoard5(board, FIVE_X, FIVE_Y);
	printf("\n");
	//�����ʵ��
	while (1)
	{
		//���1����
		PlayerMove5(board, FIVE_X, FIVE_Y);
		printf("\n");
		DisplayBoard5(board, FIVE_X, FIVE_Y);
		printf("\n");
		//�ж���Ӯ
		ret = Iswin(board, FIVE_X, FIVE_Y);
		if (ret != 'c')
		{
			break;
		}

		//���2����
		Player2Move5(board, FIVE_X, FIVE_Y);
		printf("\n");
		DisplayBoard5(board, FIVE_X, FIVE_Y);
		printf("\n");
		//�ж���Ӯ
		ret = Iswin(board, FIVE_X, FIVE_Y);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ����\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ����\n");
	}
	else
	{
		printf("   ��ƽ�֡�\n");
	}
}

void test()
{
	int input = 0;
	//ʱ������������
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		int a = 3;
		int b = 4;
		int c = 5;
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		
		//������
		case 1:
			game1();
			break;
		case 2:
			game2();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;

		//������
		case 3:
			game3();
			break;
		/*case 4:
			game();
			break;
		case 5:
			printf("�˳���Ϸ\n");
			break;
		default:*/
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}