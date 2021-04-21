#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int nw, ns, nl;
    ns = nl = 0;
    nw = 1;
    
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        
        {
            nl++;
        }
        
        if (text[i] == ' ')
        
        {
            nw++;
        }
        
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        
        {
            ns++;
        }
    }
    
    float L = (nl / (float)nw * 100);
    float S = (ns / (float)nw * 100);
    
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}