#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include <windows.h>
#include "0snake.h"

int height = 20, width = 30, x, y, fx, fy, flag, gameover, score;

int tailx[100], taily[100];
int piece = 0;

void snake_draw()
{
    system("cls"); // alter clrscr
    // Sleep(80);
    int i, j;
    for (i = 0; i <= height; i++)
    {
        for (j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                printf("%c", 178);
            }
            else
            {
                if (i == x && j == y)
                {
                    if (flag == 0)
                        printf("0");
                    if (flag == 1)
                        printf("%c", 30);
                    if (flag == 2)
                        printf("%c", 31);
                    if (flag == 3)
                        printf("%c", 17);
                    if (flag == 4)
                        printf("%c", 16);
                }
                else if (i == fx && j == fy)
                {
                    printf("@");
                }
                else
                {
                    int ch = 0;
                    for (int z = 0; z < piece; z++)
                    {
                        if (i == tailx[z] && j == taily[z])
                        {
                            ch = 1;
                            printf("o");
                        }
                    }
                    if (ch == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}