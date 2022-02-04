// leetcode ==> https://leetcode.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
     ListNode* res = NULL;
    if (head1 == NULL)
    {
        return (head2);
    }
    else if (head2 == NULL)
    {
        return (head1);
    }

    if (head1->val <= head2->val)
    {
        res = head1;
        res->next = mergeTwoLists(head1->next, head2);
    }
    else
    {
        res = head2;
        res->next = mergeTwoLists(head1, head2->next);
    }
    return (res);
    }
};