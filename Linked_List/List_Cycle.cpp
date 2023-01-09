/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) 
{
    // Approach 1 -> HashMap
    // Approach 2 -> Slow & Fast Pointer
    if (A == NULL)
        return A;
    ListNode *slow = A;
    ListNode *fast = A;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // there is cycle present
            break;
    }
    if (fast == NULL || fast->next == NULL) // No cycle is present so return NULL
        return NULL;
    slow = A;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
