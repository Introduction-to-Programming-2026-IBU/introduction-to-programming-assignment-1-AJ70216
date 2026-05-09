#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key=argv[1];
    if (strlen(key)!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i=0; i<26; i++)
    {
        for (int j=i+1; j<26; j++)
        {
            if (tolower(key[i])==tolower(key[j]))
            {
                printf("Key must not contain repeated letters.\n");
                return 1;
            }
        }
        if (!isalpha(key[i]))
        {
            printf("Key must only contain letters.\n");
            return 1;
        }
    }
    string text=get_string("plaintext: ");
    for (int i=0; i<strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            int index=text[i]-'A';
            printf("%c", toupper(key[index]));
        }
        else if (islower(text[i]))
        {
            int index=text[i]-'a';
            printf("%c", tolower(key[index]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
