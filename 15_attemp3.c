// CH*D GAYE GURU

#include<stdio.h>
#include<stdlib.h>

//sample
// [-2,-1,-1,0,1,2,2,3,4]
//   0  1  2 3 4 5 6 7 8

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    //handling bad cases
    if(numsSize<3)
    {
        (*returnSize) = 0;
        return NULL;
    }

    //campare case for qsort
    int compare(const void* a, const void* b) {
        return (*(int*)a - *(int*)b);
    }

    qsort(nums, numsSize, sizeof(int), compare); // Sort the array

    int sum, left, right, indexANSWER=0, mainSIZE = 1000;
    int **answer;
    answer = malloc(sizeof(int*) * mainSIZE);


    for(int i=0; i<numsSize-2; i++) // x, x, x, x|, x, x|
    {
        //printf("%d\n", i);
        if(nums[i] > 0){break;}
        if(i>0 && nums[i] == nums[i-1]){continue;} //handling duplication
        left = i+1;   //setting pointers intially
        right = numsSize-1;

        while(left < right)
        {
            sum = nums[left] + nums[right] + nums[i]; //sum
            if(sum == 0)
            {
                if(indexANSWER == mainSIZE)
                {
                    mainSIZE *= 2;
                    answer = realloc(answer, sizeof(int*) * mainSIZE);
                }

                answer[indexANSWER] = malloc(sizeof(int) * 3); //creating sub-array
                answer[indexANSWER][0] = nums[i];
                answer[indexANSWER][1] = nums[left];
                answer[indexANSWER][2] = nums[right];
                indexANSWER++; //incrementing size of answer

                //handling duplicates
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1]){left++;}
                while(right > left && nums[right] == nums[right+1]){right--;}
            }
            else if(sum < 0)
            {
                left++;
                while(left < right && nums[left] == nums[left-1]){left++;}
            }
            else if(sum > 0)
            {
                right--;
                while(right > left && nums[right] == nums[right+1]){right--;}
            }
        }
    }

    (*returnSize) = indexANSWER;
    (*returnColumnSizes) = malloc(sizeof(int)*indexANSWER);
    for(int i =0; i<indexANSWER; i++)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return answer;
}

int main(void)
{
    return 0;
}
