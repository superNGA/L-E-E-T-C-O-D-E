#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };



int maxDepth(struct TreeNode* root)
{
    int nonreducer=1, reducer=1;

    if(root == NULL)
    {
        return nonreducer;
    }

    //recursing function
    void depthchecker(struct TreeNode* root, int* nonreducer, int* reducer)
    {
        printf("NR : %d, R : %d", (*nonreducer), (*reducer));

        //going left
        if(root->left != NULL)
        {
            //handling increments
            if((*reducer) <= (*nonreducer)-1)
            {
                (*reducer)++;
            }else
            {
                (*reducer)++;
                (*nonreducer)++;
            }

            depthchecker(root->left, nonreducer, reducer);
        }
        //going right
        if(root->right != NULL)
        {
            //handling increments
            if((*reducer) <= (*nonreducer)-1)
            {
                (*reducer)++;
            }else
            {
                (*reducer)++;
                (*nonreducer)++;
            }

            depthchecker(root->right, nonreducer, reducer);
        }

        //kicking back data
        (*reducer)--;
    }


    depthchecker(root, &nonreducer, &reducer);
    return nonreducer;
}



int main(void)
{
    return 0;
}
