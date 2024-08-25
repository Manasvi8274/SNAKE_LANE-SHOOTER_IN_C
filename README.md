# PROJECT_C
Configurations:-
    1.Windows laptop
        a) Library used:-
        ->conio.h library(pre installed in mingw or download with it corrosponding headers);
        ->stdio.h (default)
        ->Windows.h(for time sleep)
        ->stdlib.h (random number generator)
        b) MINGW64 (works in MINGW32 also)

HOW TO USE :-
    1. Download the whole repository or clone it via github link.
    2. Then open the repository in any code editor and run main.c
    3. Choose your game and mode you want to play.
    4. ENJOY ☻☻☻☻

FEATURES :-
    1.DIFFERENT MODES - SINGLE PLAYER , DOUBLE PLAYER , TIME MODE
    2.KEEPS RECORD OF HIGHEST SCORE

GAMES :-
    1. SIMPLE SNAKE GAME
    2. SHOOT THE MONSTER(SHOOTER) GAME

CODE EXPLANATION:-
    1.SNAKE GAME:- 
        TIME COMPLEXITY - O(n^2)(as it works on both rows and columns)
        SPACE COMPLEXITY - O(m) (where m = size of snake OR m = score of player with some other variables)
    2.SHOOTER GAME:-
        TIME COMPLEXITY - O(n^2)(as it works on both rows and columns , creating monster,shooter,bullet)
        SPACE COMPLEXITY - O(a+b+c) (where a+b+c = sum of number of bullet shooted in lane_1 , lane_2 and lane_3)

WORKING ON TO ADD MORE GAMES ☻☻☻☻