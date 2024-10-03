#include<stdio.h>
#include<stdlib.h>

//sample
// [-2,-1,-1,0,1,2,2,3,4]
//   0  1  2 3 4 5 6 7 8


/*
merge less th
*/
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    if (indexANSWER == 0) {
        *returnSize = 0;
        return NULL;
    }
    else if(numsSize<3)
    {
        int a[0][0];
        return a;
    }else if(numsSize == 3 && nums[0] + nums[1] + nums[2] == 0)
    {
        int** answer;
        answer = malloc(sizeof(int*)*1);
        answer[0] = malloc(sizeof(int)*3);
        answer[0][0] = nums[0];
        answer[0][1] = nums[1];
        answer[0][2] = nums[2];

        (*returnSize) = 1;
        *returnColumnSizes = malloc(sizeof(int)*1);
        for(int i =0; i<1; i++)
        {
            (*returnColumnSizes)[i] = 3;
        }
        return answer;
    }

    int compare(const void* a, const void* b)
    {
        return (*(int*)a - *(int*)b);
    }

    qsort(nums, numsSize, sizeof(int), compare); //getting the list sorted

    int first, left, right;
    int lefter=1, righter=numsSize-1;
    int temp; //to check for repitition

    /*
    for(int i =0; i<numsSize; i++)
    {
        printf("%d ,", nums[i]);
    }*/

    int** answer; //returning this array
    int indexANSWER=0;

    for(int i=0; i<numsSize-2; i++)
    {
        if(i>0 && nums[i] == nums[i-1]){continue;}
        first = nums[i];
        lefter = i+1;
        righter = numsSize-1;
        for(int j=i+1; j<numsSize-1; j++)
        {
            left = nums[lefter];    //updating left pointer
            right = nums[righter];  //updating right pointer

            //printing for debug
            for(int x=0; x<numsSize; x++)
            {
                if(x == i || x == lefter || x == righter)
                {
                    if(nums[x] >= 0)
                    {
                       printf("x ,");
                    }else
                    {
                        printf(" x ,");
                    }
                }else
                {
                    if(nums[x] >= 0)
                    {
                       printf("  ,");
                    }else
                    {
                        printf("   ,");
                    }
                }
            }
            printf("\n");
            for(int x=0; x<numsSize; x++)
            {
                printf("%d ,", nums[x]);
            }
            printf("\n");
            printf("\n");
            //moving right pointer unitl unique value
            if(left + right > -first)
            {
                temp = nums[righter];
                while(nums[righter] == temp && righter > i)
                {
                    printf("righter--\n");
                    righter--;
                }
            }
            else if(left + right < -first) //moving left pointer unitl unique value
            {
                temp = nums[lefter];
                while(nums[lefter] == temp && lefter < numsSize)
                {
                    printf("lefter++\n");
                    lefter++;
                }
            }
            else if(left + right == -first) //if triplet FOUND
            {
                if(indexANSWER == 0)  //checking for first triplet
                {
                    answer = malloc(1*sizeof(int*));
                    answer[0] = malloc(3*sizeof(int));
                    answer[0][0] = first;
                    answer[0][1] = left;
                    answer[0][2] = right;
                    indexANSWER++;
                    lefter++;
                }
                else
                {
                    answer = realloc(answer,(indexANSWER+1)*sizeof(int*)); //increasing size of answer
                    answer[indexANSWER] = malloc(3*sizeof(int));
                    answer[indexANSWER][0] = first;
                    answer[indexANSWER][1] = left;
                    answer[indexANSWER][2] = right;
                    indexANSWER++;
                    lefter++;
                }
            }
            if(righter<=lefter) //breaking condition
            {
                break;
            }
        }

        temp = first;
    }

    (*returnSize) = indexANSWER;
    *returnColumnSizes = malloc(sizeof(int)*indexANSWER);
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
