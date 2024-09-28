#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int** answer; //creating 2d answer array
    int index_answer=0; //tracking answer index

    //checking for duplicates
    bool helper(int** answer, int first, int second,int index_answer, int third)
    {
        bool flag1 = false, flag2 = false, flag3 = false;
        for(int i=0; i<index_answer; i++) //looping through answer and camparing
        {
            if(first == answer[i][0])
            {
                flag1 = true;
                if(second == answer[i][1] || second == answer[i][2])
                {
                    flag2 = true;
                }
            }
            else if(first == answer[i][1])
            {
                flag1 = true;
                if(second == answer[i][0] || second == answer[i][2])
                {
                    flag2 = true;
                }
            }
            if(first == answer[i][2])
            {
                flag1 = true;
                if(second == answer[i][1] || second == answer[i][0])
                {
                    flag2 = true;
                }
            }

            if(flag1 && flag2)
            {
                printf("%d %d %d is at %d\n", first, second, third, i);
                return false;
            }
            flag1 = flag2 = flag3 = false;
        }

        return true;
    }

    int first,second,third;
    for(int i=0; i<numsSize-2; i++)
    {
        first = nums[i];
        for(int j = i+1; j<numsSize-1; j++)
        {
            second = nums[j];
            for(int k = j+1; k<numsSize; k++)
            {
                third = nums[k];
                if(first+second+third == 0)
                {
                    if(index_answer == 0) //for the first element
                    {
                        answer = malloc(sizeof(int*)*1); //allocating space for 1 sub-array
                        answer[index_answer] = malloc(sizeof(int)*3); //making sub array
                        answer[index_answer][0] = first;
                        answer[index_answer][1] = second;
                        answer[index_answer][2] = third;
                        index_answer++;
                    }
                    else //all other elements
                    {
                        if(helper(answer, first, second, index_answer, third)) //if no duplicates found
                        {
                            answer = realloc(answer, sizeof(int*)*(index_answer+1)); //reallocating for new triplet
                            answer[index_answer] = malloc(sizeof(int)*3); //makking sub-array
                            answer[index_answer][0] = first;
                            answer[index_answer][1] = second;
                            answer[index_answer][2] = third;
                            index_answer++;
                        }
                    }
                }
            }
        }
    }

    (*returnSize) = index_answer;
    *returnColumnSizes = malloc(sizeof(int)*index_answer);
    for(int i =0; i<index_answer; i++)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return answer;
}

int main(void)
{
    return 0;
}
