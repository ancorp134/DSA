#include<bits/stdc++.h>
//this is working fine maybe there is some compiler error but deque is correctly working
vector<int> firstNegative(vector<int> arr, int n, int k) {
   vector<int> v;
   queue<int> l;
   int i=0,j=0;
   while(j<n){
       if(arr[j]<0)	l.push(arr[j]);

       if(j-i+1<k)	j++;

	   else if(j-i+1==k){
           if(l.empty())	v.push_back(0);
           else	v.push_back(l.front());
           
           if(arr[i]==l.front()){
               l.pop();
           }
           i++;
           j++;
       }
   }
   return v;
}

// QUEUE BASED APPROACH
// vector<int> firstNegative(vector<int> arr, int n, int k) {
// 	// Write your code here.
//     deque<int> dq;
//     vector<int> ans;
    
//     //process first window of size K
//     for(int i=0;i<k;i++){
//         if(arr[i]<0) dq.push_back(i);
//     }

// 	// inserting ONLY 1 element
//     //store answer of first k sized window  (we are storing index previously)
//     if(dq.size()>0) ans.push_back(arr[dq.front()]);
//     else ans.push_back(0);
    
//     //process for remaining windows
//     for(int i=k;i<n;i++){
//    	//removal    
		//YAHI LOOp window aage badha rhaa h
// 		//iss condition ka matlab h ki aap pehli window se bahar gaye h 
		//aurr jo element dq mein pada h woh next window ka hissa nhi h
//         if(!dq.empty() && i-dq.front()>=k)
//             dq.pop_front();
//         //addition
//         if(arr[i]<0) dq.push_back(i);
        
//         //ans store
//          if(dq.size()>0) ans.push_back(arr[dq.front()]);
//    		 else ans.push_back(0);
//     }
//     return ans;
// }