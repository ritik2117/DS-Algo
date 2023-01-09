/*
Given a singly linked list, delete middle of the linked list.
For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element.
For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
Return the head of the linked list after removing the middle node.
If the input linked list has 1 node, then this node should be deleted and a null node should be returned.
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
    ListNode *head = A;
    if (head == NULL || head->next == NULL)
        return NULL;
    // Using Fast & Slow pointer Approach
    ListNode *prev;
    ListNode *slow = A;
    ListNode *fast = A;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    return head;
}