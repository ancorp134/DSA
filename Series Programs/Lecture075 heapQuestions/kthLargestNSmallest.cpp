leetcode ==>https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //USING SIMPLE ARRAY APPROACH IN T.C.= O(n*logn)
     // sort(nums.begin(),nums.end());
     // int element=nums[nums.size()-k];
     //    return element;
        
        //USING MAX HEAP
        priority_queue<int> pq(nums.begin(),nums.begin()+nums.size());
        int ans;
//kth SMALLEST ELEMENT
      // int n=nums.size() - k;
      // while(n--) q.pop();
      // return q.top();
        
//kth LARGEST ELEMENT
        while(k--){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};