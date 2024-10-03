#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void convert(char* s, int numRows)
{
    int oscilation=0;
    bool backed = false;

    for(int i =0; i<8; i++)
    {
        if(backed == false)
        {
            oscilation++;
        }else
        {
            oscilation--;
        }

        printf("%d\n", oscilation);

        if(oscilation == numRows-1)
        {
            backed = true;
        }else if(oscilation == 0)
        {
            backed = false;
        }
    }
}

int main(void)
{
    convert("PAYPALISHIRING", 4);
    return 0;
}
