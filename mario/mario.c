#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n, a, b, c;
    do
    {
        n = get_int("Height: "); 
    }
    while (n < 1 || n > 8);
    
    for (a = 0; a < n; a++)
    {
        for (c = 0; c < n - a - 1 ; c++)
        {
            printf(" ");
        }
        for (b = 0; b <= a; b++)
        {
            printf("#");
        }
        printf("  ");
        for (b = 0; b <= a; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}