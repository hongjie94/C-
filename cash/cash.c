#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float d;
    
    do
    {
        d = get_float("How much change is owed?： ");
    }
    while (d <= 0);
    
    int cents = round(d * 100);
    int coins = 0;
    
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    
    printf("You wll need at least %i coins \n", coins);
}