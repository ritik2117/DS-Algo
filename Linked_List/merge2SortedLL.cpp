/*
Merge two sorted linked lists, A and B, and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists and 
should also be sorted.
Input: A = 5 -> 8 -> 20
       B = 4 -> 11 -> 15
Output: 4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    ListNode *head,*temp;
    if (A->val <= B->val)
    {
        head = A;
        A = A->next;
    }
    else
    {
        head = B;
        B = B->next;
    }
    temp = head; // temp would be at last node of merged LL
    while (A != NULL && B != NULL)
    {
        if (A->val <= B->val)
        {
            temp->next = A;
            temp = A;
            A = A->next;
        }
        else
        {
            temp->next = B;
            temp = B;
            B = B->next;
        }
    }
    if (A == NULL)
        temp->next = B;
    else
        temp->next = A;
    return head;
}
