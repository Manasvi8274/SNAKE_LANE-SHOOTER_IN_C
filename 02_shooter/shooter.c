#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "1shooter.h"

int main()
{
    int height = 30, width = 30, score = 0, gameover = 0, l1 = 0, l2 = 0, l3 = 1, life = 3;
    int monst_lane = -1, monst_1[6][2] = {{2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}}, monst_2[6][2] = {{2, 14}, {2, 15}, {2, 16}, {3, 14}, {3, 15}, {3, 16}}, monst_3[6][2] = {{2, 24}, {2, 25}, {2, 26}, {3, 24}, {3, 25}, {3, 26}};
    int n_bullet_l1 = 0, n_bullet_l2 = 0, n_bullet_l3 = 0;
    int bullet_l1[1000], bullet_l2[1000], bullet_l3[1000];
    clock_t st = clock();
    monst_lane = 0;
    while ((clock() - st) < (15 * CLOCKS_PER_SEC))
    {
        printf("\033[0;35m");
        // monst_lane = rand() % 3;
        shooter_draw(&bullet_l1, &bullet_l2, &bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_input(&bullet_l1, &bullet_l2, &bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_logic(&bullet_l1, &bullet_l2, &bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        // Sleep(100);
    }
    printf("\033[0;37m");
    // printf("YOUR SCORE IS : %d",score);
    FILE *fptr = fopen("1shooter_High_Score", "r");
    char strx[100];
    int x = atoi(fgets(strx, 100, fptr));
    fclose(fptr);
    if (x > score)
    {
        printf("YOUR SCORE IS : %d\n", score);
        printf("HIGHEST SCORE : %d\n", x);
        printf("YOU LOSE BY : %d", x - score);
    }
    else
    {
        printf("YOUR SCORE : %d\n", score);
        printf("CONGRATULATIONS , YOU BEAT THE HIGH SCORE by %d\n", score - x);
        FILE *fptr = fopen("1shooter_High_Score", "w");
        fprintf(fptr, "%d", score);
        fclose(fptr);
    }
    return 0;
}