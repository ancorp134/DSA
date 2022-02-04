 vector<int> plusOne(vector<int>& digits) {
     
    int n = digits.size()-1;
	for (int i = n; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
            // increase the digit by one
			digits[i]++;
			return digits;
		}
	}
        // this is for the case of all 9's
        // add 1 at the starting and 0 at the end
		digits[0] =1;
		digits.push_back(0);
        
        return digits;
    }
LinkedListNode<int> *addOneToList(LinkedListNode<int> *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
        return head;
    LinkedListNode<int> *temp = head;
    //isolating -1 from the end of the input denoting the end of linked list
    while(temp -> next -> next != NULL)
	{
		temp = temp -> next;
	}
	end = temp -> next;
	temp -> next = NULL;
    temp=head;
    vector<int> v;
    while (temp)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
   vector<int> res = plusOne(v);
   int i=0;
   temp=head;
   while(temp->next!=NULL)
   {
       temp->data=v[i++];
       temp = temp->next;
   }
   // Add ‘end’ at the of the list
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = end;

	// Return head
   return head;
}