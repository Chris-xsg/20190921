#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"������.h"

void InitBoard(char arr[ROW][COL], int row, int col)//��ʼ�����̣���ά���� 3*3
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
}
void Display(char arr[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	printf("----------\n");
	for (i = 0; i < row; i++)
	{
		printf("|");
		for (j = 0; j < col; j++)
		{
			printf("%2c|", arr[i][j]);
		}
		printf("\n----------\n");
	}
}
void Computer(char arr[ROW][COL], int row, int col)//���������������
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'O';
			break;
		}
	}
}
void Player(char arr[ROW][COL], int row, int col)//������� ��  �� ��
{
	int x = 0;
	int y = 0;
	while (1)
	{
		scanf("%d,%d", &x, &y);
		x--;
		y--;
		if ((0 <= x && x <= row - 1) && (0 <= y && y <= col - 1))
		{
			if (arr[x][y] == ' ')
			{
				arr[x][y] = 'X';
				break;
			}
			else {
				printf("����λ���ظ�\n");
			}
		}
		else {
			printf("����������������\n");
		}
	}
}
int Checkfull(char arr[ROW][COL], int row, int col)//�ж������Ƿ�Ϊ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	for (j = 0; j < col; j++)
	{
		if (arr[i][j] == ' ')
			return 1;
	}
	return 0;
}
char Win(char arr[ROW][COL], int row, int col)//�ж���Ӯ 
{
	int i = 0;
	if (Checkfull(arr, ROW, COL) == 0)
	{
		return 'P';
	}
	for (i = 0; i < row; i++)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && (arr[i][2] != ' '))
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]) && (arr[2][i] != ' '))
		{
			return arr[0][i];
		}
	}
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && (arr[2][2] != ' '))
	{
		return arr[0][0];
	}
	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) && (arr[2][0] != ' '))
	{
		return arr[0][2];
	}
	return ' ';
}
int meau()//�˵�
{
	printf("***************************************\n");
	printf("*************** 1. play  **************\n");
	printf("*************** 0. exit  **************\n");
	printf("***************************************\n");
	return 0;
}
void game()
{
	char arr[ROW][COL];
	InitBoard(arr, ROW, COL);
	while (1)
	{
		printf("������\n");
		Computer(arr, ROW, COL);
		Display(arr, ROW, COL);
		if (Win(arr, ROW, COL) != ' ')
		{
			break;
		}
		printf("�����\n");
		Player(arr, ROW, COL);
		Display(arr, ROW, COL);
		if (Win(arr, ROW, COL) != ' ')
		{
			break;
		}
	}
	if (Win(arr, ROW, COL) == 'X')
	{
		printf("���Ӯ\n");
	}
	else if (Win(arr, ROW, COL) == 'O')
	{
		printf("����Ӯ\n");
	}
	else if (Win(arr, ROW, COL) == 'P')
	{
		printf("ƽ��\n");
	}
}

int main()
{
	int a = 0;
	do{
		meau();
		printf("��ѡ��");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������������\n");
		}
	} while (a);
	system("pause");
	return 0;
}
