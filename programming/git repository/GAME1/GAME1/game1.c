

#include"game1.h"

//棋盘宫格3
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

//棋盘初始化3
void DisplayBoard3(char board[ROW][COL], int row, int col)
{
	//方法1
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
	//方法2
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

//宫格初始化5
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

//棋盘初始化5
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


//下棋实现

//三子棋--玩家1下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家1下棋:>>>\n");
	while (1)
	{ 
		printf("请输入要下的坐标:>>>");
		scanf("%d%d", &x, &y);
		//坐标判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("已经下过棋了\n");
			}
		}
		else
		{
			printf("坐标错误请重新输入！\n");
			break;
		}
	}
	
}
//三子棋--玩家2下棋
void Player2Move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家2下棋:>>>\n");
	while (1)
	{
		printf("请输入要下的坐标:>>>");
		scanf("%d%d", &x, &y);
		//坐标判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("已经下过棋了\n");
			}
		}
		else
		{
			printf("坐标错误请重新输入！\n");
			break;
		}
	}

}

//五子棋--玩家1下棋
void PlayerMove5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家1下棋:>>>\n");
	while (1)
	{
		printf("请输入要下的坐标:>>>");
		scanf("%d%d", &x, &y);
		//坐标判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("已经下过棋了\n");
			}
		}
		else
		{
			printf("坐标错误请重新输入！\n");
			break;
		}
	}

}
//五子棋--玩家2下棋
void Player2Move5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家2下棋:>>>\n");
	while (1)
	{
		printf("请输入要下的坐标:>>>");
		scanf("%d%d", &x, &y);
		//坐标判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("已经下过棋了\n");
			}
		}
		else
		{
			printf("坐标错误请重新输入！\n");
			break;
		}
	}

}


//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋:>>>\n");
	
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

//判断棋局结束
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

//输赢判断三子棋
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	// '\'方向判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	// '/'方向判断
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//平局判断
	if (1 == isfull(board, ROW, COL))
	{
		return 'q';
	}
	return 'c';
}


//判断棋局结束
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

//输赢判断五子棋
char Iswin5(char board[FIVE_X][FIVE_Y], int row, int col)
{
	int i = 0;
	int j = 0;
	//横16行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖16列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	// '\'方向判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	// '/'方向判断
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//平局判断
	if (1 == isfull5(board, FIVE_X, FIVE_Y))
	{
		return 'q';
	}
	return 'c';
}