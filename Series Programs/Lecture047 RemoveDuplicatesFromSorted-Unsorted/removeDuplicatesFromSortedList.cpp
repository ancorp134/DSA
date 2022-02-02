// leetcode ==> https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        //empty list
        if(head==NULL)
            return head;
        
        //non empty list
        ListNode* temp=head;
        while(temp){
            if((temp->next!=NULL) && temp->val==temp->next->val){
              ListNode* next_next=temp->next->next;
              ListNode* next=temp->next;
              delete(next);
                //in this line we have still shifted only the pointer to next node not entire temp
              temp->next=next_next;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};