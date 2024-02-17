
#define ROW 3
#define COL 3

#define FIVE_X 16
#define FIVE_Y 16

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//空格宫格
void InitBoard3(char board[ROW][COL], int row, int col);
void InitBoard5(char board[FIVE_X][FIVE_Y], int row, int col);


//棋盘打印（初始化）
void DisplayBoard3(char board[ROW][COL], int row, int col);
void DisplayBoard5(char board[FIVE_X][FIVE_Y], int row, int col);


//下棋实现
void PlayerMove(char board[ROW][COL], int row, int col);
void Player2Move(char board[ROW][COL], int row, int col);
void PlayerMove5(char board[FIVE_X][FIVE_Y], int row, int col);
void Player2Move5(char board[FIVE_X][FIVE_Y], int row, int col);


//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//输赢判断
char Iswin(char board[ROW][COL], int row, int col);
int isfull(char board[ROW][COL], int row, int col);
//"*"玩家赢
//"#"电脑赢
//"q"平局
//"c"继续
