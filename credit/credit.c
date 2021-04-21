#include <stdio.h>
#include <cs50.h>
void printf_credit_card_brand(long cn);
bool check_validity(long cn);
int find_length(long cn);
bool checksum(long cn);

int main(void)
{
    long cn;
    do
    {
        cn = get_long("Card Number?: ");
    }
    while (cn < 0);

    if (check_validity(cn) == true)
    {
    
        printf_credit_card_brand(cn);
    
    }
    
    else
    {
        printf("INVALID\n");
    }

}

bool check_validity(long cn)
{
    int len = find_length(cn);
    return ((len == 13 || len == 15 || len == 16) && checksum(cn));  
}

int find_length(long cn)
{
    int len;
    for (len = 0; cn != 0; cn /= 10, len++);
    return len;
}

bool checksum(long cn)
{
    int sum = 0;
    for (int i = 0; cn != 0; i++,  cn /= 10)
    {
        if (i % 2 == 0)
        
        {
            
            sum += cn % 10;
            
        }
  
        else
        {
            int digit = 2 * (cn % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return sum % 10 == 0;
} 
void printf_credit_card_brand(long cn)
{
       
    if ((cn >= 34e13 && cn < 35e13) || (cn >= 37e13 && cn < 38e13))
    
    {
        printf("AMEX\n");
    }
    
    
            
    else if (cn >= 51e14 && cn < 56e14)
    
    {
            
        printf("MASTERCARD\n");
        
    }
    
    else if ((cn >= 4e12 && cn < 5e12) || (cn >= 4e15 && cn < 5e15))
    
    {
            
        printf("VISA\n");
         
    }
     
    else
       
    {
        printf("INVALID\n");
    }
} 