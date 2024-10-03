#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    int middle;

    bool checker(struct TreeNode* root)
    {
        struct TreeNode* left = root;
        struct TreeNode* right= root;
        int bkleft=0, bkright=0;
        while(1)
        {
            if(left->left != NULL)
            {
                bkleft++;
                left = left->left;
            }
            else
            {
                break;
            }
        }
        while(1)
        {
            if(right->right != NULL)
            {
                bkright++;
                right = right->right;
            }
            else
            {
                break;
            }
        }

        if(bkleft != bkright)
        {
            return false;
        }else{ return true;}

    }

    void treeadder_left(int* nums,struct TreeNode* current, int middle)
    {

        for(int i = middle-1; i>=0; i--)
        {
        //creating newnode
        struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newnode->left = NULL;
        newnode->right = NULL;

        newnode->val = nums[i];

        current->left = newnode;
        current = current->left;

        free(newnode);
        }
    }

    void treeadder_right(int* nums,struct TreeNode* current, int middle, int numsSize)
    {

        for(int i = middle+1; i<numsSize; i++)
        {
        //creating newnode
        struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newnode->left = NULL;
        newnode->right = NULL;

        newnode->val = nums[i];

        current->right = newnode;
        current = current->right;

        free(newnode);
        }
    }


    //creating root node and setting the value
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* current = root;
    root->left = NULL;
    root->right = NULL;
    if(numsSize%2 == 0)
    {
        middle = numsSize/2
        root->val = nums[middle];
    }else
    {
        middle = (numsSize-1)/2
        root->val = nums[middle];
    }

    //calling the adding function
    treeadder_left(nums, current, middle);
    treeadder_right(nums, current, middle, numsSize);

    return root;
}


int main(void)
{

    return 0;
}
