#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "01_snake/0snake.c"
#include "01_snake/0snake.h"
#include "02_shooter/shooter.c"
#include "02_shooter/queue.c"

int main()
{
    // system("cls");
    clock_t start = clock();
    snake_setup();
    while (!gameover && ((clock() - start) < (100 * CLOCKS_PER_SEC)))
    {
        snake_input();
        snake_draw();
        snake_makelogic();
    }
    system("cls");
    snake_draw_gameover();
    printf("%d", score * 10);
    return 0;
}