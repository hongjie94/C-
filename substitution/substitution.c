#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
bool validte_key(string vk);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!validte_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string difference = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
    
    {
        difference[i - 'A'] = toupper(difference[i - 'A']) - i;
    }
    
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            
            plaintext[i] = plaintext[i] + difference[plaintext[i] - (isupper(plaintext[i]) ? 'A' : 'a')];
        }
        
        printf("%c", plaintext[i]);
    }
    
    printf("\n");
}

bool validte_key(string vk)
{
    int len = strlen(vk);
    if (len != 26)
    
    {
        return false;
    }
    
    int freq[26] = { 0 };
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(vk[i]))
        {
            return false;
        }
       
        int index = toupper(vk[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }

        freq[index]++;
    }

    return true;
}