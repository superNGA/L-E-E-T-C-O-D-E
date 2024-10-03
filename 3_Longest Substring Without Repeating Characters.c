#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int shit(char *s)
{
    //weird cases
    if(strlen(s) == 0 || strlen(s) == 1)
    {
        return strlen(s);
    }

    int start=0, end = 1;

    //infinity loop
    while(1)
    {
        printf("from %c <-> %c\n", s[start], s[end-1]);

        //checking
        for(int i = start; i<end; i++)
        {
            for( int j = i; j<end; j++)
            {
                if(s!=j)
                {
                    if(s[j] == s[i])
                    {
                        start++; //if repetition found, move staring point
                    }
                }
            }
        }

        end++; //moving ending point regardless

        //ending codition
        if(s[end] == '\0')
        {
            break;
        }
    }
}

int main(void)
{
    printf("\n%d", shit("powkp"));
    return 0;
}
