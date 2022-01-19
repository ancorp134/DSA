// single Number ==> LeetCode
// find Unique ==> codeStudio

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int numssize=nums.size();
        
        for(int i=0;i<numssize;i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};