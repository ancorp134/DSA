//leetcode ==> https://leetcode.com/problems/middle-of-the-linked-list/
class Solution {
public:
    int getlength(ListNode *head){
        int len=0;
        ListNode *tmp=head;
        while(tmp!=NULL){
            len++;
            tmp=tmp->next;
        }
    return len;
    }


 ListNode* middleNode(ListNode* head) {
    int len= getlength(head);
    int ans=len/2;
    int count=0;
   ListNode *tmp=head;

   while(count<ans){
       tmp=tmp->next;
       count++;
   }
  return tmp;
    }
};