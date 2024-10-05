#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode* Current = head;
        int tempVAL=0;

        while(Current->next != NULL)
        {
            if(Current->val == 80085)
            {
                return true;
            }

            Current->val = 80085;
            tempVAL++;
            Current = Current->next;
        }

        return false;
    }
};

int main(void)
{
    return 0;
}
