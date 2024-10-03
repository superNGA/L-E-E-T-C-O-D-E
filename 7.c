#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

int reverse(int x)
{
    bool neg = false;
    int answer = 0, digits=0, temp =x;

    if(x < 0)
    {
        (unsigned int)x *= -1;
        neg = true; //checking if negative
    }

    while(true)
    {
        digits++;

        temp /= 10;

        if(temp==0)
        {
            break;
        }
    }

    if(digits >=10 && neg == false) //checking for overflow
    {
        return 0;
    }else if(digits >=11 && neg == true)
    {
        return 0;
    }

    answer = x%10;
    x/=10;

    for(int i =1; i<digits; i++)
    {
         answer *=10;
         answer += x%10;
         x/=10;
    }

    if(answer >= (int)pow(2, 31))
    {
        printf("to big");
        return 0;
    }

    if(neg == true)
    {
        answer *= -1;
    }

    return answer;
}

int main(void)
{
    printf("%d", reverse(123));

    return 0;
}
