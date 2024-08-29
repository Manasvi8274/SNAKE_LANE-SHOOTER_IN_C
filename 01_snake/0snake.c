#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "0snake.h"

int main()
{
    int height = 20, width = 30, x = 0, y = 0, fx = 0, fy = 0, flag=0, gameover = 0, score = 0;

    int tailx[100], taily[100];
    int piece = 0;
    snake_setup(&x, &y, &fx, &fy, &height, &width, &score, &gameover);
    printf("x=%d,y=%d",x,y);
    Sleep(1000);
    while (!gameover)
    {
        snake_draw(&height, &width, &x, &y, &fx, &fy, &flag, tailx, taily, &piece);
        snake_logic(&height, &width, &x, &y, &fx, &fy, &flag, tailx, taily, &piece, &gameover, &score);
        snake_input(&flag);
    }
    system("cls");
    snake_draw_gameover(&height, &width);
    FILE *fptr = fopen("0snake_High_Score", "r");
    char strx[100];
    int old_score = atoi(fgets(strx, 100, fptr));
    fclose(fptr);
    if (old_score > score)
    {
        printf("YOUR SCORE IS : %d\n", score);
        printf("HIGHEST SCORE : %d\n", old_score);
        printf("YOU LOSE BY : %d", old_score - score);
    }
    else
    {
        printf("YOUR SCORE : %d\n", score);
        printf("CONGRATULATIONS , YOU BEAT THE HIGH SCORE by %d\n", score - old_score);
        FILE *fptr = fopen("0snake_High_Score", "w");
        fprintf(fptr, "%d", score);
        fclose(fptr);
    }
    return 0;
}