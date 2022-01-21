// THIS IS CORRECT SOLUTION WORKING ON THE TEST CASESES

// vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
// 	// Write your code here.
//    vector< vector<int> > ans;
//    int sum=K;
//    for(int i=0;i<arr.size(); i++ ) {
//    		for(int j = i+1; j<arr.size(); j++) {            
//             for(int k=j+1;k<arr.size();k++){
//                 if(arr[i] +arr[j] +arr[k] == sum){
//             	vector<int> temp;
//                 temp.push_back(arr[i]);
//                 temp.push_back(arr[j]);
//                 temp.push_back(arr[k]);
// 				ans.push_back(temp);
//                     return ans;
//             }
//             }        	
//         }
//    }
// //    sort(ans.begin(), ans.end());
//    return ans;
// }

// 2nd APPROACH ALSO REMOVES DUPLICATES
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
   vector< vector<int> > ans;
   int sum=K;
   for(int i=0;i<arr.size(); i++ ) {
   		for(int j = i+1; j<arr.size(); j++) {            
            for(int k=j+1;k<arr.size();k++){
                if(arr[i] +arr[j] +arr[k] == sum){
            	vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
				ans.push_back(temp);
//                     i++;
                    j++;
                    k++;
//                     goto end;
            }
            }        	
        }
   }
    sort(ans.begin(), ans.end());
ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}