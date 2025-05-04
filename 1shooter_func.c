#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void shooter_logic(int *bullet_l1, int *bullet_l2, int *bullet_l3, int monst_1[][2], int monst_2[][2], int monst_3[][2], int *n_bullet_l1, int *n_bullet_l2, int *n_bullet_l3, int *monst_lane, int *height, int *width, int *score, int *gameover, int *l1, int *l2, int *l3)
{
    Sleep(50);
    for (int b = 0; b < *n_bullet_l1; b++)
    {
        if (bullet_l1[b] == 3 && *monst_lane == 0)
        {
            *score = *score + 10;
            Beep(500, 200);
            int l;
        label_l1:
            l = rand() % 3;
            if (l == 0)
                goto label_l1;
            else
            {
                *monst_lane = l;
            }
        }
    }
    for (int b = 0; b < *n_bullet_l2; b++)
    {
        if (bullet_l2[b] == 3 && *monst_lane == 1)
        {
            *score = *score + 10;
            Beep(500, 200);
            int l;
        label_l2:
            l = rand() % 3;
            if (l == 1)
                goto label_l2;
            else
            {
                *monst_lane = l;
            }
        }
    }
    for (int b = 0; b < *n_bullet_l3; b++)
    {
        if (bullet_l3[b] == 3 && *monst_lane == 2)
        {
            *score = *score + 10;
            Beep(500, 200);
            int l;
        label_l3:
            l = rand() % 3;
            if (l == 2)
                goto label_l3;
            else
            {
                *monst_lane = l;
            }
        }
    }
}

void shooter_input(int *bullet_l1, int *bullet_l2, int *bullet_l3, int monst_1[][2], int monst_2[][2], int monst_3[][2], int *n_bullet_l1, int *n_bullet_l2, int *n_bullet_l3, int *monst_lane, int *height, int *width, int *score, int *gameover, int *l1, int *l2, int *l3)
{
    if (kbhit())
    {
        switch (getch())
        {
        case 75:
        {
            if (*l1 == 1)
            {
                break;
            }
            else if (*l2 == 1)
            {
                *l2 = 0;
                *l1 = 1;
                break;
            }
            else if (*l3 == 1)
            {
                *l3 = 0;
                *l2 = 1;
                break;
            }
        }
        case 77:
        {
            if (*l3 == 1)
            {
                break;
            }
            else if (*l2 == 1)
            {
                *l2 = 0;
                *l3 = 1;
                break;
            }
            else if (*l1 == 1)
            {
                *l2 = 1;
                *l1 = 0;
                break;
            }
        }
        case 32:
        {
            if (*l1 == 1)
            {
                bullet_l1[*n_bullet_l1] = 25;
                *n_bullet_l1 = *n_bullet_l1 + 1;
                break;
                // }
            }
            else if (*l2 == 1)
            {

                bullet_l2[*n_bullet_l2] = 25;
                *n_bullet_l2 = *n_bullet_l2 + 1;
                break;
            }
            else if (*l3 == 1)
            {

                bullet_l3[*n_bullet_l3] = 25;
                *n_bullet_l3 = *n_bullet_l3 + 1;
                break;
            }
        }
        }
    }
}

void shooter_draw(int *bullet_l1, int *bullet_l2, int *bullet_l3, int monst_1[][2], int monst_2[][2], int monst_3[][2], int *n_bullet_l1, int *n_bullet_l2, int *n_bullet_l3, int *monst_lane, int *height, int *width, int *score, int *gameover, int *l1, int *l2, int *l3)
{
    system("cls");
    for (int i = 0; i <= *height; i++)
    {
        for (int j = 0; j <= *width; j++)
        {

            if (i == 0 || i == 26 || i == *height || j == 0 || j == 10 || j == 20 || j == *width)
            {
                printf("%c", 178);
            }
            else
            {
                int fg = 0;
                if (*n_bullet_l1 || *n_bullet_l2 || *n_bullet_l3)
                {
                    for (int b = 0; b < *n_bullet_l1; b++)
                    {
                        if (i == bullet_l1[b] && j == 5)
                        {
                            printf("\033[0;33m%c", 179);
                            printf("\033[0;35m");
                            bullet_l1[b]--;
                            fg = 1;
                        }
                    }
                    for (int b = 0; b < *n_bullet_l2; b++)
                    {
                        if (i == bullet_l2[b] && j == 15)
                        {
                            printf("\033[0;34m%c", 179);
                            printf("\033[0;35m");
                            bullet_l2[b]--;
                            fg = 1;
                        }
                    }
                    for (int b = 0; b < *n_bullet_l3; b++)
                    {
                        if (i == bullet_l3[b] && j == 25)
                        {
                            printf("\033[0;32m%c", 179);
                            printf("\033[0;35m");
                            bullet_l3[b]--;
                            fg = 1;
                        }
                    }
                }
                if (*l1 == 1)
                {
                    if (i == 29 && (j >= 3 && j <= 7))
                    {
                        printf("\033[0;33m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                    else if (i == 28 && (j >= 4 && j <= 6))
                    {
                        printf("\033[0;33m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                    else if (i == 27 && (j == 5))
                    {
                        printf("\033[0;33m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                }
                else if (*l2 == 1)
                {
                    if (i == 29 && (j >= 13 && j <= 17))
                    {
                        printf("\033[0;34m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                    else if (i == 28 && (j >= 14 && j <= 16))
                    {
                        printf("\033[0;34m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                    else if (i == 27 && (j == 15))
                    {
                        printf("\033[0;34m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                }
                else if (*l3 == 1)
                {
                    if (i == 29 && (j >= 23 && j <= 27))
                    {
                        printf("\033[0;32m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                    else if (i == 28 && (j >= 24 && j <= 26))
                    {
                        printf("\033[0;32m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                    else if (i == 27 && (j == 25))
                    {
                        printf("\033[0;32m%c", 176);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                }
                if (i <= 25 && *monst_lane == 0)
                {
                    if ((i == monst_1[0][0] && j == monst_1[0][1]) || (i == monst_1[1][0] && j == monst_1[1][1]) || (i == monst_1[3][0] && j == monst_1[3][1]) || (i == monst_1[4][0] && j == monst_1[4][1]) || (i == monst_1[5][0] && j == monst_1[5][1]) || (i == monst_1[2][0] && j == monst_1[2][1]))
                    {
                        printf("\033[0;33m%c", 15);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                }
                else if (i <= 25 && *monst_lane == 1)
                {
                    if ((i == monst_2[0][0] && j == monst_2[0][1]) || (i == monst_2[2][0] && j == monst_2[2][1]) || (i == monst_2[3][0] && j == monst_2[3][1]) || (i == monst_2[4][0] && j == monst_2[4][1]) || (i == monst_2[5][0] && j == monst_2[5][1]) || (i == monst_2[1][0] && j == monst_2[1][1]))
                    {
                        printf("\033[0;34m%c", 15);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                }
                else if (i <= 25 && *monst_lane == 2)
                {
                    if ((i == monst_3[0][0] && j == monst_3[0][1]) || (i == monst_3[2][0] && j == monst_3[2][1]) || (i == monst_3[3][0] && j == monst_3[3][1]) || (i == monst_3[4][0] && j == monst_3[4][1]) || (i == monst_3[5][0] && j == monst_3[5][1]) || (i == monst_3[1][0] && j == monst_3[1][1]))
                    {
                        printf("\033[0;32m%c", 15);
                        printf("\033[0;35m");
                        fg = 1;
                    }
                }
                if (fg == 1)
                {
                    continue;
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
