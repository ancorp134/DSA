class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> numsCopy(n);  
            // Rotate the elements.
            for (int i = 0; i < n; i++)
            {
                //logic to rotate the array which is just add the k and take % with the size of array to get appropriate location
                numsCopy[(i + k)%n] = nums[i];
            }
        nums=numsCopy;
    }
};