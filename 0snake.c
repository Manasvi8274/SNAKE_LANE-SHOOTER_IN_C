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
void snake_draw_gameover()
{
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
                // if(i == 9 && j==6)
                // 	printf("G");
                // if (i == 9 && j == 7)
                // 	printf("A");
                // if (i == 9 && j == 8)
                // 	printf("M");
                // if (i == 9 && j == 9)
                // 	printf("E");
                // if (i == 9 && j == 10)
                // 	printf("O");
                // if (i == 9 && j == 11)
                // 	printf("V");
                // if (i == 9 && j == 12)
                // 	printf("E");
                // if (i == 9 && j == 13)
                // 	printf("R");
                if (i == 9 && (j == 11))
                {
                    printf("G");
                    // Sleep(50);
                    printf("A");
                    // Sleep(50);
                    printf("M");
                    // Sleep(50);
                    printf("E");
                    // Sleep(50);
                    printf("O");
                    // Sleep(50);
                    printf("V");
                    // Sleep(50);
                    printf("E");
                    // Sleep(50);
                    printf("R");
                    // Sleep(50);
                }
                else if (i == 9 && (j <= 18 && j >= 11))
                    continue;

                else
                    printf(" ");
            }
        }
        printf("\n");
    }
    Beep(1000, 20);
    Beep(900, 20);
    Beep(800, 20);
    Beep(700, 20);
    Beep(600, 20);
    Beep(500, 20);
    Beep(400, 20);
    Beep(300, 20);
}
