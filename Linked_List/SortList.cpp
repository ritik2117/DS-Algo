/*
Sort a linked list, A in O(n log n) time using constant space complexity.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Merge(ListNode *h1, ListNode *h2)
{
    ListNode *head,*temp;
    if (h1->val <= h2->val)
    {
        head = h1;
        h1 = h1->next;
    }
    else
    {
        head = h2;
        h2 = h2->next;
    }
    temp = head; // temp would be at last node of merged LL
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->val <= h2->val)
        {
            temp->next = h1;
            temp = h1;
            h1 = h1->next;
        }
        else
        {
            temp->next = h2;
            temp = h2;
            h2 = h2->next;
        }
    }
    if (h1 == NULL)
        temp->next = h2;
    else
        temp->next = h1;
    return head;
}

ListNode *getFirstMid(ListNode *head)
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

ListNode* MergeSort(ListNode *head)
{
    // Base case
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *h1, *h2;
    ListNode *mid = getFirstMid(head);
    h2 = mid->next;
    mid->next = NULL;
    h1 = MergeSort(head);
    h2 = MergeSort(h2);
    return Merge(h1, h2);
}

ListNode* Solution::sortList(ListNode* A) 
{
    A = MergeSort(A);
    return A;
}