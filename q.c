#include <conio.h>
#include <stdio.h>
#include <Windows.h>

int main()
{
    int n=0;
    int b[n];
    b[n++] = 0;
    b[n++] = -1;
    for (int i = 0; i < n; i++)
    {
        // if (sizeof(b[i]) == sizeof(int))
        printf("%d\n", b[i]);
    }
}