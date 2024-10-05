#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
    void adder(TreeNode* root, vector<int>& answer)
        {
            if(root == NULL)
            {
                return;
            }

            answer.push_back(root->val);
            adder(root->left, answer);
            adder(root->right, answer);
            return;
        }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> answer;

        if(root == NULL)
        {
            return answer;
        }

        adder(root, answer);

        return answer;
    }
};

int main(void)
{
    return 0;
}
