//codestudio ==> remove duplicates from unsorted linked list


#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{
//1ST APPROACH
    // using nested loops in O(n^2)
//   if(head==NULL) {return head;}
//   Node* temp = head;
//   while(temp!=NULL){
//       Node* curr = temp->next ;
// 	  Node* prev=temp;
//       while(curr!= NULL) {
// 		  if(temp->data==curr->data){
//               prev->next=curr->next;
//               delete (curr);
//               curr=prev->next;
//           }            
//             else{  
//                 prev=curr;
//                 curr=curr->next;
//             }          
// 		}
//       temp=temp->next;
//   }
//     return head;

//2nd APPROACH
    //using unordered map
    unordered_map<int,bool> m;
    Node* curr = head;
    m[curr->data] = true;
    Node* temp = curr;
    curr=curr->next;
    while(curr!=NULL){
        if(m[curr->data]){
            temp->next = curr->next;
            free(curr);
        }
        else{
             m[curr->data]=true;
            temp = curr;
        }
       curr = temp->next;
    }
    return head;
}