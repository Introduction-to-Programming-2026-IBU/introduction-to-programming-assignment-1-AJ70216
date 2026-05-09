#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string text=get_string("Text: ");
    int letters=0;
    int words=1;
    int sentences=0;
    for (int i=0; i<strlen(text); i++)
    {
        if ((text[i]>='A'&&text[i]<='Z')||(text[i]>='a'&&text[i]<='z'))
        {
            letters++;
        }
        if (text[i]==' ')
        {
            words++;
        }
        else if (text[i]=='.'||text[i]=='!'||text[i]=='?')
        {
            sentences++;
        }
    }
    float L=(float)letters/words*100;
    float S=(float)sentences/words*100;
    int index=0.0588*L-0.296*S-15.8;
    if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else if (index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
