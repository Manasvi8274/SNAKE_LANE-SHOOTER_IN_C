#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void play_single_player_snake()
{
    int height = 20, width = 30, x = 0, y = 0, fx = 0, fy = 0, flag = 0, gameover = 0, score = 0;

    int tailx[100], taily[100];
    int piece = 0;
    snake_setup(&x, &y, &fx, &fy, &height, &width, &score, &gameover);
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
};
void play_double_player_snake()
{
    int timeslice;
    printf("Enter the time slice for each person : ");
    scanf("%d", &timeslice);

    // player 1
    int height = 20, width = 30, x = 0, y = 0, fx = 0, fy = 0, flag = 0, gameover = 0, score = 0;
    int p1_tailx[100], p1_taily[100];
    int piece = 0;
    snake_setup(&x, &y, &fx, &fy, &height, &width, &score, &gameover);
    char p1_name[100];
    printf("PLAYER ONE TURN\nENTER YOUR NAME\n");
    scanf("%s", &p1_name);
    printf("LOADING .");
    Sleep(700);

    system("cls");
    clock_t start = clock();
    while (!gameover && ((clock() - start) < (timeslice * CLOCKS_PER_SEC)))
    {
        snake_draw(&height, &width, &x, &y, &fx, &fy, &flag, p1_tailx, p1_taily, &piece);
        snake_logic(&height, &width, &x, &y, &fx, &fy, &flag, p1_tailx, p1_taily, &piece, &gameover, &score);
        snake_input(&flag);
    }
    int p1_score = score;
    system("cls");
    snake_draw_gameover(&height, &width);
    Sleep(1000);
    system("cls");

    // player 2
    height = 20, width = 30, x = 0, y = 0, fx = 0, fy = 0, flag = 0, gameover = 0, score = 0;
    int p2_tailx[100], p2_taily[100];
    piece = 0;
    snake_setup(&x, &y, &fx, &fy, &height, &width, &score, &gameover);
    char p2_name[100];
    printf("PLAYER TWO TURN\nENTER YOUR NAME\n");
    scanf("%s", &p2_name);
    printf("LOADING .");
    Sleep(700);

    system("cls");
    start = clock();
    while (!gameover && ((clock() - start) < (timeslice * CLOCKS_PER_SEC)))
    {
        snake_draw(&height, &width, &x, &y, &fx, &fy, &flag, p2_tailx, p2_taily, &piece);
        snake_logic(&height, &width, &x, &y, &fx, &fy, &flag, p2_tailx, p2_taily, &piece, &gameover, &score);
        snake_input(&flag);
    }
    int p2_score = score;
    system("cls");
    snake_draw_gameover(&height, &width);
    Sleep(1000);
    system("cls");

    if (p1_score > p2_score)
    {
        printf("%d WINS THIS ROUND AGAINST %s BY %d POINTS/n", p1_name, p2_name, p1_score - p2_score);
    }
    else if (p1_score == p2_score)
    {
        printf("MATCH TIE BETWEEN %s AND %s./n", p1_name, p2_name);
    }
    else
    {
        printf("%s WINS THIS ROUND AGAINST %s BY %d POINTS/n", p2_name, p1_name, p2_score - p1_score);
    }
};
void play_single_player_shooter()
{
    int height = 30, width = 30, score = 0, gameover = 0, l1 = 0, l2 = 0, l3 = 1, life = 3;
    int monst_lane = -1, monst_1[6][2] = {{2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}}, monst_2[6][2] = {{2, 14}, {2, 15}, {2, 16}, {3, 14}, {3, 15}, {3, 16}}, monst_3[6][2] = {{2, 24}, {2, 25}, {2, 26}, {3, 24}, {3, 25}, {3, 26}};
    int n_bullet_l1 = 0, n_bullet_l2 = 0, n_bullet_l3 = 0;
    int bullet_l1[1000], bullet_l2[1000], bullet_l3[1000];
    clock_t st = clock();

    int timeslice;
    printf("Enter the time slice for play : ");
    scanf("%d", &timeslice);

    monst_lane = 0;
    while ((clock() - st) < (timeslice * CLOCKS_PER_SEC))
    {
        printf("\033[0;35m");
        shooter_draw(&bullet_l1, &bullet_l2, &bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_input(&bullet_l1, &bullet_l2, &bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_logic(&bullet_l1, &bullet_l2, &bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
    }
    printf("\033[0;37m"); // default color
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
};
void play_double_player_shooter()
{
    int timeslice;
    printf("Enter the time slice for play : ");
    scanf("%d", &timeslice);
    int height = 30, width = 30, score = 0, gameover = 0, l1 = 0, l2 = 0, l3 = 1, life = 3;
    int monst_lane = -1, monst_1[6][2] = {{2, 4}, {2, 5}, {2, 6}, {3, 4}, {3, 5}, {3, 6}}, monst_2[6][2] = {{2, 14}, {2, 15}, {2, 16}, {3, 14}, {3, 15}, {3, 16}}, monst_3[6][2] = {{2, 24}, {2, 25}, {2, 26}, {3, 24}, {3, 25}, {3, 26}};
    ///////////////////////////////////player 1 turn

    int n_bullet_l1 = 0, n_bullet_l2 = 0, n_bullet_l3 = 0;
    int p1_bullet_l1[1000], p1_bullet_l2[1000], p1_bullet_l3[1000];

    char p1_name[100];
    printf("PLAYER ONE TURN\nENTER YOUR NAME\n");
    scanf("%s", &p1_name);
    printf("LOADING .");
    Sleep(300);

    system("cls");
    clock_t st = clock();
    monst_lane = 0;
    while ((clock() - st) < (timeslice * CLOCKS_PER_SEC))
    {
        printf("\033[0;35m");
        shooter_draw(&p1_bullet_l1, &p1_bullet_l2, &p1_bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_input(&p1_bullet_l1, &p1_bullet_l2, &p1_bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_logic(&p1_bullet_l1, &p1_bullet_l2, &p1_bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
    }
    printf("\033[0;37m"); // default color
    int p1_score = score;
    system("cls");
    Sleep(500);

    ///////////////////////////////////player 2 turn
    score = 0;
    gameover = 0;
    l1 = 0;
    l2 = 0;
    l3 = 1;
    life = 3;
    monst_lane = -1;
    n_bullet_l1 = 0, n_bullet_l2 = 0, n_bullet_l3 = 0;
    int p2_bullet_l1[1000], p2_bullet_l2[1000], p2_bullet_l3[1000];

    char p2_name[100];
    printf("PLAYER TWO TURN\nENTER YOUR NAME\n");
    scanf("%s", &p2_name);
    printf("LOADING .");
    Sleep(300);

    system("cls");
    st = clock();
    monst_lane = 0;
    while ((clock() - st) < (timeslice * CLOCKS_PER_SEC))
    {
        printf("\033[0;35m");
        shooter_draw(&p2_bullet_l1, &p2_bullet_l2, &p2_bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_input(&p2_bullet_l1, &p2_bullet_l2, &p2_bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
        shooter_logic(&p2_bullet_l1, &p2_bullet_l2, &p2_bullet_l3, &monst_1, &monst_2, &monst_3, &n_bullet_l1, &n_bullet_l2, &n_bullet_l3, &monst_lane, &height, &width, &score, &gameover, &l1, &l2, &l3);
    }
    printf("\033[0;37m"); // default color
    int p2_score = score;
    system("cls");

    if (p1_score > p2_score)
    {
        printf("%s WINS THIS ROUND AGAINST %s BY %d POINTS\n", p1_name, p2_name, p1_score - p2_score);
    }
    else
    {
        printf("%s WINS THIS ROUND AGAINST %s BY %d POINTS\n", p2_name, p2_name, p2_score - p1_score);
    }
};