// codestudio ==> https://www.codingninjas.com/codestudio/problems/is-it-a-circular-linked-list_981265?leftPanelTab=1
/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/

bool circularLL(Node* head)
{
    // Write your code here
     if(head==NULL)
        return true;
   
    Node* temp=head->next;
    while(temp){
        temp=temp->next;
        if(temp==head)
            return true;
    }
    return false;
}
