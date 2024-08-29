#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"



int main()
{
    system("cls");
    printf("Enter the game number you want to play.(1 or 2 or 3)\n");
    printf("1.SNAKE\n2.SHOOTER(time mode)\n3.EXIT");
    int choice;
    scanf("%d",&choice);
    while(1){
        if(choice == 1){
            printf("Enter the mode number you want to play.(1 or 2)\n");
            printf("1.SINGLE PLAYER\n2.DOUBLE PLAYER(time mod)\n3.RETURN\n4.EXIT");
            while(1){
                if(choice == 1){
                    play_single_player_snake();
                }
                else if (choice == 2){
                    play_double_player_snake();
                }
                else if (choice == 3){
                    break;
                }
                else if (choice == 4){
                    return 0;
                }
            }
        }
        else if(choice == 2){
            printf("Enter the mode number you want to play.(1 or 2)\n");
            printf("1.SINGLE PLAYER(time mode)\n2.DOUBLE PLAYER(time mode)\n3.RETURN\n4.EXIT");
            while (1)
            {
                if (choice == 1){
                    play_single_player_shooter();
                }
                else if (choice == 2){
                    play_double_player_shooter();
                }
                else if (choice == 3){
                    break;
                }
                else if (choice == 4){
                    return 0;
                }
            }
        }
        else if(choice == 3){
            return 0;
        }
    }
}