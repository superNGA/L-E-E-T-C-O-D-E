#include<stdio.h>
#include<stdlib.h>


struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int minDepth(struct TreeNode* root)
{
    int temp=80085, R=1;

    //handling stupid inputs
    if(root == NULL)
    {
        return 0;
    }

    //moving through the tree
    void circulator(struct TreeNode* root, int* R, int* temp)
    {
        if(root == NULL)
        {
            return;
        }

        if(root!=NULL && root->left == NULL && root->right == NULL)
        {
            if((*R)<(*temp))
            {
                (*temp) = (*R);
            }
        }

        (*R)++;

        circulator(root->left, R, temp);
        circulator(root->right, R, temp);

        (*R)--;
    }

    circulator(root, &R, &temp);

    return temp;
}

int main(void)
{
    return 0;
}
