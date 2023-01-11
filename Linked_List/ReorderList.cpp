/*
Given a singly linked list A
    A: A0 → A1 → … → An-1 → An 
reorder it to:
    A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values.
Input:  A = [1, 2, 3, 4, 5] 
Output:  [1, 5, 2, 4, 3] 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* getFirstMid(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* ReverseLL(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxt = curr->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (nxt != NULL)
            nxt = nxt->next;
    }
    head = prev;
    return head;
}

ListNode* Solution::reorderList(ListNode* A) 
{
    if (A->next == NULL)
        return A;
    // First break the linked list in 2 halfs
    ListNode *mid = getFirstMid(A);
    ListNode *h2 = mid->next;
    mid->next = NULL;
    // Reverse the 2nd half of linked list
    h2 = ReverseLL(h2);
    // Merge both linked list alternatively
    ListNode *temp = A;
    ListNode *nxt = temp->next;
    while (h2 != NULL)
    {
        temp->next = h2;
        temp = h2;
        h2 = nxt;
        nxt = temp->next;
    }
    return A;
}