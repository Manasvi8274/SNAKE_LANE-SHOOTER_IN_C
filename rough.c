#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <fcntl.h>
#include <string.h>

// int main()
// {
//     FILE *fptr;
//     fptr = fopen("shooter_High_Score", "r");
//     // fclose(fptr);
//     // fptr = fopen("shooter_High_Score", "r");
//     char x[100];
//     // fgets(x, 100, fptr);
//     int y = atoi(fgets(x, 100, fptr));
//     // printf("%s\n", x);
//     fclose(fptr);
//     printf("%d\n", y);
//     fptr = fopen("shooter_High_Score", "w");
//     fprintf(fptr, "100");
//     fclose(fptr);
//     // for (int i = 0; i < 5; i++)
//     // {
//     // }
//     // return 0;
// }
int *x(int *c)
{
    printf("%d", *c - 1);
}
int main()
{
    int y = 123;
    x(&y);
}