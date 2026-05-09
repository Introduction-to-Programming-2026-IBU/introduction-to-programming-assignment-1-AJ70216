#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k=atoi(argv[1]);
    string text=get_string("plaintext: ");
    for (int i=0; i<strlen(text); i++)
    {
       if (text[i]>='A'&&text[i]<='Z')
       {
           printf("%c", ((text[i]-'A'+k)%26)+'A');
       }
       else if (text[i]>='a'&&text[i]<='z')
       {
           printf("%c", ((text[i]-'a'+k)%26)+'a');
       }
       else
       {
           printf("%c", text[i]);
       }
    }
    printf("\n");
}
