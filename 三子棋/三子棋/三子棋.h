#pragma once
#ifndef _SANZIQI_H_
#define _SANZIQI_H_
#define ROW 3
#define COL 3
void InitBoard(char arr[ROW][COL], int row, int col);//��ʼ��
void Display(char arr[ROW][COL], int row, int col);//��ӡ����
void Computer(char arr[ROW][COL], int row, int col);//������
void Player(char arr[ROW][COL], int row, int col);//�����
int Checkfull(char arr[ROW][COL], int row, int col);//�ж������Ƿ�Ϊ��
char Win(char arr[ROW][COL], int row, int col);//�ж���Ӯ
#endif
