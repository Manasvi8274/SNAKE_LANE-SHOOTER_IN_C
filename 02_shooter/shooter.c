#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "queue.c"

int height = 30, width = 30, x, y, score = 0, gameover = 0, l1 = 0, l2 = 0, l3 = 1, life = 3;
int monst_lane = -1, monst_1[6][2] = {{2, 3}, {2, 4}, {2, 5}, {3, 3}, {3, 4}, {3, 5}}, monst_2[6][2] = {{2, 13}, {2, 14}, {2, 15}, {3, 13}, {3, 14}, {3, 15}}, monst_3[6][2] = {{2, 23}, {2, 24}, {2, 25}, {3, 23}, {3, 24}, {3, 25}};
int n_bullets = 0;
queue bullet;

void draw()
{
    system("cls");
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {

            if (i == 0 || i == 26 || i == height || j == 0 || j == 10 || j == 20 || j == width)
            {
                printf("%c", 178);
            }
            else
            {
                if(n_bullets > 0){
                    // queue = 
                    // while()
                    if (i == bullet.x && j = bullet.y);
                }
                if (l1 == 1)
                {
                    if (i == 29 && (j >= 3 && j <= 7))
                    {
                        printf("\033[0;33m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 28 && (j >= 4 && j <= 6))
                    {
                        printf("\033[0;33m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 27 && (j == 5))
                    {
                        printf("\033[0;33m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 29 || i == 28 || i == 27)
                        printf(" ");
                }
                else if (l2 == 1)
                {
                    if (i == 29 && (j >= 13 && j <= 17))
                    {
                        printf("\033[0;34m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 28 && (j >= 14 && j <= 16))
                    {
                        printf("\033[0;34m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 27 && (j == 15))
                    {
                        printf("\033[0;34m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 29 || i == 28 || i == 27)
                        printf(" ");
                }
                else if (l3 == 1)
                {
                    if (i == 29 && (j >= 23 && j <= 27))
                    {
                        printf("\033[0;32m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 28 && (j >= 24 && j <= 26))
                    {
                        printf("\033[0;32m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 27 && (j == 25))
                    {
                        printf("\033[0;32m%c", 176);
                        printf("\033[0;35m");
                    }
                    else if (i == 29 || i == 28 || i == 27)
                        printf(" ");
                }
                if (i <= 25 && monst_lane == 0)
                {
                    if ((i == monst_1[0][0] && j == monst_1[0][1]) || (i == monst_1[1][0] && j == monst_1[1][1]) || (i == monst_1[3][0] && j == monst_1[3][1]) || (i == monst_1[4][0] && j == monst_1[4][1]) || (i == monst_1[5][0] && j == monst_1[5][1]) || (i == monst_1[2][0] && j == monst_1[2][1]))
                    {
                        printf("\033[0;33m%c", 15);
                        printf("\033[0;35m");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else if (i <= 25 && monst_lane == 1)
                {
                    if ((i == monst_2[0][0] && j == monst_2[0][1]) || (i == monst_2[2][0] && j == monst_2[2][1]) || (i == monst_2[3][0] && j == monst_2[3][1]) || (i == monst_2[4][0] && j == monst_2[4][1]) || (i == monst_2[5][0] && j == monst_2[5][1]) || (i == monst_2[1][0] && j == monst_2[1][1]))
                    {
                        printf("\033[0;34m%c", 15);
                        printf("\033[0;35m");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                else if (i <= 25 && monst_lane == 2)
                {
                    if ((i == monst_3[0][0] && j == monst_3[0][1]) || (i == monst_3[2][0] && j == monst_3[2][1]) || (i == monst_3[3][0] && j == monst_3[3][1]) || (i == monst_3[4][0] && j == monst_3[4][1]) || (i == monst_3[5][0] && j == monst_3[5][1]) || (i == monst_3[1][0] && j == monst_3[1][1]))
                    {
                        printf("\033[0;32m%c", 15);
                        printf("\033[0;35m");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    clock_t st = clock();
    // monst_lane = 1;
    while ((clock() - st) < (5 * CLOCKS_PER_SEC))
    {
        printf("\033[0;35m");
        monst_lane = rand() % 3;
        draw();
        Sleep(100);
    }
    return 0;
}