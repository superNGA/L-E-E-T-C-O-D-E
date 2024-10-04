//there a vizualize in the comment

#include<stdio.h>
#include<stdlib.h>

int threeSumClosest(int* nums, int numsSize, int target)
{
    //manage edge cases here
    if(numsSize <= 3)
    {
        int counter=0;
        for(int i=0; i<numsSize; i++)
        {
            counter += nums[i];
        }
        return counter;
    }

    // Compare function for qsort
    int compare(const void* a, const void* b)
    {
        return (*(int*)a - *(int*)b);
    }
    qsort(nums, numsSize, sizeof(int), compare); // Sort the array


    int center, left, right, teemp = nums[0] + nums[1] + nums[numsSize-1], sum;

    for(int i=0; i<numsSize-2; i++)
    {
        if(i>0 && nums[i] == nums[i-1]){continue;} //handling repition

        center = nums[i];
        left = i+1;
        right = numsSize-1;

        while(left < right)
        {
            /*
            //build visualizer
            for(int k=0; k<numsSize; k++)
            {
                if(k == i || k == left || k == right)
                {
                    printf("  x,");
                }
                else
                {
                    printf("   ,");
                }
            }
            printf("\n");
            for(int k=0; k<numsSize; k++)
            {
                if(nums[k] >= 0)
                {
                    printf("  %d,", nums[k]);
                }
                else
                {
                    printf(" %d,", nums[k]);
                }
            }
            printf("\nsum : %d\n\n", sum); */

            sum = center + nums[left] + nums[right]; //getting the sum

            if(sum > target) //sum on the right of target ( on number line )
            {
                right--;
                while(nums[right] == nums[right+1] && right > left){right--;}

            }
            else if(sum < target) //sum on the left of target ( on number line )
            {
                left++;
                while(nums[left] == nums[left-1] && left < right){left++;}
            }
            else if(sum == target)
            {
                return sum; //straight exit
            }

            if(abs(sum - target) < abs(teemp - target))
            {
                teemp = sum;
            }
        }
    }

    return teemp;
}

int main(void)
{
    return 0;
}
