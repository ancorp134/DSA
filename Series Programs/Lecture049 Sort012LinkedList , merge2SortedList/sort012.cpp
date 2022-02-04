// codeStudio ==> https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=1

/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
#include<bits/stdc++.h>
Node* sortList(Node *head)
{
    // Write your code here.
    if(head==nullptr || head->next==nullptr)
            return head;
        vector <int> v;
        Node* temp=head;
        while(temp){
            v.push_back(temp->data);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        temp=head;
        int i=0;
        while(temp){
            temp->data=v[i++];
            temp=temp->next;
        }
        return head;

}
