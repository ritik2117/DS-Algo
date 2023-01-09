/*
Reverse a linked list A from position B to C.
NOTE: Do it in-place and in one-pass.
Input: A = 1 -> 2 -> 3 -> 4 -> 5
       B = 2
       C = 4
Output: 1 -> 4 -> 3 -> 2 -> 5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    int i;
    ListNode *tail = A;
    // Placing the tail pointer at the C position
    i = 1;
    while (i < C && tail != NULL)
    {
        tail = tail->next;
        i++;
    }
    // Start the reversal from B to C
    ListNode *curr = A;
    i = 1;
    while (i < B-1)
    {
        curr = curr->next;
        i++;
    }
    ListNode *nxt = curr->next;
    if (B != 1)
    {
        curr->next = tail;
        curr = nxt;
        if (nxt != NULL)
            nxt = nxt->next;
        i++;
    }
    ListNode *prev = tail->next;
    while (i <= C)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (nxt != NULL)
            nxt = nxt->next;
        i++;
    }
    if (B == 1)
        A = tail;
    return A;
}