
#define ROW 3
#define COL 3

#define FIVE_X 16
#define FIVE_Y 16

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�ո񹬸�
void InitBoard3(char board[ROW][COL], int row, int col);
void InitBoard5(char board[FIVE_X][FIVE_Y], int row, int col);


//���̴�ӡ����ʼ����
void DisplayBoard3(char board[ROW][COL], int row, int col);
void DisplayBoard5(char board[FIVE_X][FIVE_Y], int row, int col);


//����ʵ��
void PlayerMove(char board[ROW][COL], int row, int col);
void Player2Move(char board[ROW][COL], int row, int col);
void PlayerMove5(char board[FIVE_X][FIVE_Y], int row, int col);
void Player2Move5(char board[FIVE_X][FIVE_Y], int row, int col);


//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//��Ӯ�ж�
char Iswin(char board[ROW][COL], int row, int col);
int isfull(char board[ROW][COL], int row, int col);
//"*"���Ӯ
//"#"����Ӯ
//"q"ƽ��
//"c"����
