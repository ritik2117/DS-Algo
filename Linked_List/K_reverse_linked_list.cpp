/*
Given a singly linked list A and an integer B, 
reverse the nodes of the list B at a time and return the modified linked list.
TC: 
Input: A = [1, 2, 3, 4, 5, 6]
       B = 2
Output: [2, 1, 4, 3, 6, 5]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) 
{
    int i,j;
    // For first B nodes - so that new head to be assigned
    ListNode *head = A;
    ListNode *tail = head;
    for (i=1; i<B; i++)
        tail = tail->next;
    ListNode *curr = head;
    ListNode *prev = tail->next;
    ListNode *nxt = curr->next;
    for (i=0; i<B; i++)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (nxt != NULL)
            nxt = nxt->next;
    }
    A = tail;
    // For next (N/B)-1 nodes
    while (nxt != NULL)
    {
        tail = curr;
        for (i=1; i<B; i++)
            tail = tail->next;
        head->next = tail;
        head = curr;
        prev = tail->next;
        for (i=0; i<B; i++)
        {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if (nxt != NULL)
                nxt = nxt->next;
        }
    }
    return A;
}