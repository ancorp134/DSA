// leetcode ==> https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         string a, b;
        ListNode *result = nullptr;
        while(l1) { a.push_back(l1->val); l1 = l1->next;}
        while(l2) { b.push_back(l2->val); l2 = l2->next;}
        int l = a.size()-1, r = b.size()-1, carry = 0;
        
        while(l >= 0 || r >= 0 || carry == 1) {
            int c = (l >= 0 ? a[l--] : 0) + ( r >= 0 ? b[r--] : 0) + carry;
            ListNode *temp = new ListNode(c%10);
            temp->next = result;
            // cout << c%10;
            result = temp;
            carry = c/10;
        }    
       
        return result;
    }
};