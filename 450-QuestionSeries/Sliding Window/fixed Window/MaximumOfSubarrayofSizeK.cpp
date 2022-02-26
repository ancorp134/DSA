//leetcode ==> https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
      vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            //starting wale element ko delete kar rahe h sliding window mein
            //removing out of bound (window) elements
            //will not work for the first window
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            
            //remove smaller number in k range as they are waste
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            // if we have reached the window size (k-1 as the index start from 0) push                      elements into the ans
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};