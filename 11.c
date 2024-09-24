#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int maxArea(int* height, int heightSize)
{
    int lefter=0, righter = heightSize -1,temp, bigger =0;
    int left = height[lefter];
    int right = height[righter];

    while(1)
    {
            //moving limiters and storing area
            if(left <= right)
            {
                temp = (righter - lefter) * left;
                lefter++;
                left = height[lefter];
            }else
            {
                temp = (righter - lefter) * right;
                righter--;
                right = height[righter];
            }

            //storing max
            if(temp > bigger)
            {
                bigger = temp;
            }

            printf("%d <-> %d * %d : %d\n", left, right, righter - lefter, temp);

            //breaking
            if(righter == lefter)
            {
                break;
            }
    }

    return bigger;
}

int main(void)
{
    int sample[] = {1,8,6,2,5,4,8,3,7};
    printf("%d",maxArea(sample, 9));

    return 0;
}
