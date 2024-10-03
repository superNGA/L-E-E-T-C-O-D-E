#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int maxArea(int* height, int heightSize)
{
    int smaller, temp =0, current;

    for( int i = 0; i<heightSize; i++)
    {
        for( int j = i; j<heightSize; j++)
        {
            if(height[i] >= height[j])
            {
                smaller = height[j];
            }else
            {
                smaller = height[i];
            }

            current = smaller * (j-i);

            if(current > temp)
            {
                printf("( %d <-> %d ) * %d\n", i, j, current);
                temp = current;
            }
        }
    }

    return temp ;
}

int main(void)
{
    int sample[] = {1,8,6,2,5,4,8,3,7};
    printf("%d", maxArea(sample, 9));

    return 0;
}
