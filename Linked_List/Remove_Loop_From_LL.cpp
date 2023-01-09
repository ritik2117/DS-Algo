/*
You are given a linked list that contains a loop.
You need to find the node, which creates a loop and break it by making the node point to NULL.
Input: 3 -> 2 -> 4 -> 5 -> 6
          ^         |
          |         |    
          - - - - - -
Output: 3 -> 2 -> 4 -> 5 -> 6 -> NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) 
{
    ListNode *slow = A;
    ListNode *fast = A;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // there is cycle present
            break;
    }
    slow = A;
    // slow = fast -> where the cycle begins
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
    return A;
}