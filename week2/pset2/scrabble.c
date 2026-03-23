#include <cs50.h>
#include <stdio.h>
#include <string.h>
int POINTS[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int main(void)
{
    string word1=get_string("Player 1: ");
    string word2=get_string("Player 2: ");
    int score1=0;
    int score2=0;
    for (int i=0; i<strlen(word1); i++)
    {
        char c=word1[i];
        if (c>='A'&&c<='Z')
        {
            score1=score1+POINTS[c-'A'];
        }
        else if (c>='a'&&c<='z')
        {
            score1=score1+POINTS[c-'a'];
        }
    }
    for (int i=0; i<strlen(word2); i++)
    {
        char c=word2[i];
        if (c>='A'&&c<='Z')
        {
            score2=score2+POINTS[c-'A'];
        }
        else if (c>='a'&&c<='z')
        {
            score2=score2+POINTS[c-'a'];
        }
    }
    if (score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2>score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
