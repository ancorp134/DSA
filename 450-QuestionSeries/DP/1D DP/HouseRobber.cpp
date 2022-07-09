// leetcode==> https://leetcode.com/problems/house-robber/
// Time Complexity: O(N )
// Space Complexity: O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size());
        dp[0]=nums[0];
        // dp[1]=nums[1];
        //incase there are only 2 elements in nums
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};