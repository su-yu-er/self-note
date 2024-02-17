

#include"game1.h"

//���̹���3
void InitBoard3(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//���̳�ʼ��3
void DisplayBoard3(char board[ROW][COL], int row, int col)
{
	//����1
	int i = 0;
	/*
	printf(" ---------- \n");
	printf("|   |   |   |\n");
	printf("|---|---|---|\n");
	printf("|   |   |   |\n");
	printf("|---|---|---|\n");
	printf("|   |   |   |\n");
	printf(" ----------- \n");
	*/
	//����2
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1 )
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//�����ʼ��5
void InitBoard5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//���̳�ʼ��5
void DisplayBoard5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}


//����ʵ��

//������--���1����
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���1����:>>>\n");
	while (1)
	{ 
		printf("������Ҫ�µ�����:>>>");
		scanf("%d%d", &x, &y);
		//�����ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�Ѿ��¹�����\n");
			}
		}
		else
		{
			printf("����������������룡\n");
			break;
		}
	}
	
}
//������--���2����
void Player2Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���2����:>>>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>>>");
		scanf("%d%d", &x, &y);
		//�����ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("�Ѿ��¹�����\n");
			}
		}
		else
		{
			printf("����������������룡\n");
			break;
		}
	}

}

//������--���1����
void PlayerMove5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���1����:>>>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>>>");
		scanf("%d%d", &x, &y);
		//�����ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�Ѿ��¹�����\n");
			}
		}
		else
		{
			printf("����������������룡\n");
			break;
		}
	}

}
//������--���2����
void Player2Move5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("���2����:>>>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>>>");
		scanf("%d%d", &x, &y);
		//�����ж�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("�Ѿ��¹�����\n");
			}
		}
		else
		{
			printf("����������������룡\n");
			break;
		}
	}

}


//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("��������:>>>\n");
	
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж���ֽ���
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
		
	}
	return 1;
}

//��Ӯ�ж�������
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	// '\'�����ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	// '/'�����ж�
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//ƽ���ж�
	if (1 == isfull(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';
}


//�ж���ֽ���
int isfull5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}

	}
	return 1;
}

//��Ӯ�ж�������
char Iswin5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int i = 0;
	int j = 0;
	//��16��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//��16��
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	// '\'�����ж�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	// '/'�����ж�
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//ƽ���ж�
	if (1 == isfull5(board, FIVE_X, FIVE_Y))
	{
		return 'q';
	}
	return 'c';
}