// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        Node* cur=head;
        Node* temp;
        while(cur){
            temp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=temp;
            cur=temp;
        }
        
        cur=head;
        while(cur){
            cur->next->random=cur->random ? cur->random->next : cur->random;
            cur=cur->next->next;
        }
        Node* original=head;
        Node* copy=head->next;
        temp=copy;
        while(original and copy){
            original->next=original->next->next;
            copy->next=copy->next ? copy->next->next : copy->next;
            original=original->next;
            copy=copy->next;
        }
        return temp;
    }
};

//MAP BASED APPROACH
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         map<Node*, Node*> m;
//         int i=0;
//         Node* ptr = head;
//         while (ptr) {
//             m[ptr] =new Node(ptr->val);
//             ptr = ptr->next;
//         }
//         ptr = head;
//         while (ptr) {
//             m[ptr]->next = m[ptr->next];
//             m[ptr]->random = m[ptr->random];
//             ptr = ptr->next;
//         }
//         return m[head];
//     }
// };