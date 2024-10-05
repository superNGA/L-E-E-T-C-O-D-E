/*
This algoritm is used to detect cyles in a linked list.
runs in O(n) time and is very effective.
It goes like this:
    There are 2 pointers, One moves 1 at a time and the other moves 2 at a time.
    eventually both of them will land on the same node.
    if they do, their is a cycle in the linked list.
    else their is no cycle.
*/

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
    bool hasCycle(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode* slow = head; //move 1 at a time
        ListNode* fast = head; //move 2 at a time

        while(fast != NULL || fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) //cycle detected
            {
                return true;
            }
        }

        return false;
    }
};

int main(void)
{
    return 0;
}
