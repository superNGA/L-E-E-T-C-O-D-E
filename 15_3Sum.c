#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
   int TEMPstorage[100][3]; //temp storage
   int bufferSTORAGE[3]; //temp temp sotrage
   int first, second, third; //triplet numbers
   int index_tempstorage=0; //tracking TEMPstorage index

   //checking for repitition
   bool helper(int* tocheck, int domain_to_check[][3], int index_tempstorage)
   {
       bool flag1 = false, flag2 = false;

       for( int i=0; i<index_tempstorage; i++) //looping through temp storage array
       {
           if(tocheck[0] == domain_to_check[i][0] || tocheck[0] == domain_to_check[i][1] || tocheck[0] == domain_to_check[i][2])
           {
               flag1 = true;
           }
           if(tocheck[1] == domain_to_check[i][0] || tocheck[1] == domain_to_check[i][1] || tocheck[1] == domain_to_check[i][2])
           {
               flag2 = true;
           }
       }

       if(flag1 == true && flag2 == true) //returning false if duplicate found
       {
            return false;
       }
       return true;
   }

   //getting the triplets
   for(int i=0; i<numsSize; i++)
   {
       if(i == numsSize-3)//testing breaking condition
       {
           break;
       }

       first = nums[i];
       for(int j =i+1; j<numsSize; j++)
       {
           second = nums[j];
           for( int k = j+1; k<numsSize; k++)
           {
                    third = nums[k];
                    if(first + second + third == 0) //checking condition and storing triplets
                    {
                        if(index_tempstorage == 0)
                        {
                            TEMPstorage[0][0] = first;
                            TEMPstorage[0][1] = second;
                            TEMPstorage[0][2] = third;
                            index_tempstorage++;
                            printf("%d %d %d for %d\n", first, second, third, index_tempstorage);
                        }
                        else
                        {
                            bufferSTORAGE[0] = first;
                            bufferSTORAGE[1] = second;
                            bufferSTORAGE[2] = third;
                            if(helper(bufferSTORAGE, TEMPstorage, index_tempstorage)) //calling helper
                            {
                                TEMPstorage[index_tempstorage][0] = first;
                                TEMPstorage[index_tempstorage][1] = second;
                                TEMPstorage[index_tempstorage][2] = third;
                                index_tempstorage++;
                                printf("%d %d %d for %d\n", first, second, third, index_tempstorage);
                            }
                        }
                    }
               }
           }
       }

    int** answer = malloc(index_tempstorage*sizeof(int*)); //creating main array
    for(int i =0; i<index_tempstorage; i++) //creating sub-arrays and storing values
    {
        answer[i] = malloc(3*sizeof(int));
        answer[i][0] = TEMPstorage[i][0];
        answer[i][1] = TEMPstorage[i][1];
        answer[i][2] = TEMPstorage[i][2];
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

   return answer;
}

int main(void)
{
    return 0;
}
