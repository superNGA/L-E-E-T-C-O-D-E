#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };



bool isBalanced(struct TreeNode* root)
{
    int NR_left=1, R_left=1, NR_right, R_right;
    bool answer = true;

    //depth checking function
    void depthchecker(struct TreeNode* root, int* NR, int* R)
    {
        if(root == NULL)
        {
            return;
        }

        //handling increments
        if((*R) <= (*NR)-1)
        {
            (*R)++;
        }
        else
        {
            (*R)++;
            (*NR)++;
        }

        //recursing
        depthchecker(root->left, NR, R);
        depthchecker(root->right, NR, R);

        //handling returns
        (*R)--;
    }

    //feeds nodes in depthchecker
    void feeder(struct TreeNode* root, int* NR_left, int* R_left, int* NR_right, int* R_right, bool* answer)
    {
        //stoping recusion
        if(root == NULL)
        {
            return;
        }else if((*answer) == false)
        {
            return;
        }

        //resseting values
        (*NR_right) =1;
        (*NR_left) = 1;
        (*R_left) = 1;
        (*R_right) = 1;

        //calling helper functions
        depthchecker(root->left, NR_left, R_left);
        depthchecker(root->right, NR_right, R_right);

        //checking values
        if((*NR_left) - (*NR_right) == 1 || (*NR_left) - (*NR_right) == -1 || (*NR_left) - (*NR_right) == 0)
        {
            (*answer) = true;
        }
        else
        {
            (*answer) = false;
        }

        //recuring
        feeder(root->left, NR_left, R_left, NR_right, R_right, answer);
        feeder(root->right, NR_left, R_left, NR_right, R_right, answer);
    }

    feeder(root, &NR_left, &R_left, &NR_right, &R_right, &answer);
    return answer;
}

int main(void)
{
    return 0;
}
