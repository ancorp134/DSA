// codestudio giving tle for everyone check on GFG
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    // Write your code here.
    //here the logic written myself is same as of GFG
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
