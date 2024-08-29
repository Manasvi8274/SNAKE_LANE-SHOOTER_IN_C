#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"
#include "0snake.h"
#include "1shooter.h"

int main()
{
    system("cls");
    while (1)
    {
        printf("\nEnter the game number you want to play.(1 or 2 or 3)\n");
        printf("1.SNAKE\n2.SHOOTER(time mode)\n3.EXIT\n");
        int choice;
        scanf("%d", &choice);
        system("cls");

        if (choice == 1)
        {
            int flag = 1;
            while (1 && flag)
            {
                printf("\nEnter the mode number you want to play.(1 or 2)\n");
                printf("1.SINGLE PLAYER\n2.DOUBLE PLAYER(time mod)\n3.RETURN\n4.EXIT\n");
                int mode;
                scanf("%d", &mode);
                system("cls");
                if (mode == 1)
                {
                    play_single_player_snake();
                }
                else if (mode == 2)
                {
                    play_double_player_snake();
                }
                else if (mode == 3)
                {
                    flag = 0;
                }
                else if (mode == 4)
                {
                    return 0;
                }
                system("cls");
            }
        }
        else if (choice == 2)
        {
            system("cls");

            int flag = 1;
            while (1 && flag)
            {
                printf("\nEnter the mode number you want to play.(1 or 2)\n");
                printf("1.SINGLE PLAYER(time mode)\n2.DOUBLE PLAYER(time mode)\n3.RETURN\n4.EXIT\n");
                int mode;
                scanf("%d", &mode);
                if (mode == 1)
                {
                    play_single_player_shooter();
                }
                else if (mode == 2)
                {
                    play_double_player_shooter();
                }
                else if (mode == 3)
                {
                    flag = 0;
                }
                else if (mode == 4)
                {
                    return 0;
                }
                system("cls");
            }
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
}