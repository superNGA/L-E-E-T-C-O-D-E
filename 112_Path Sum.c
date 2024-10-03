#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


bool hasPathSum(struct TreeNode* root, int targetSum)
{
    int reducer=0;
    bool answer = false;

    //recurring function
    void cisculator(struct TreeNode* root, int* reducer, bool* answer, int* targetSum)
    {
        printf("reducer value : %d", (*reducer));

        //kick backs
        if(root == NULL || (*answer) == true)
        {
            return;
        }

        //increments
        (*reducer) += root->val;

        //setting answer
        if(root->left == NULL && root->right == NULL && (*reducer) == (*targetSum))
        {
            (*answer) = true;
            printf("pp\n");

        }

        //recurring
        cisculator(root->left, reducer, answer, targetSum);
        cisculator(root->right, reducer, answer, targetSum);

        //adjustments
        (*reducer) -= root->val;
    }

    cisculator(root, &reducer, &answer, &targetSum);

    return answer;
}


int main(void)
{
    return 0;
}
