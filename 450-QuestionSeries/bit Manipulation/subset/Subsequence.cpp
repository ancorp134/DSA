#include <bits/stdc++.h>
using namespace std;

// Finding Subsequence/subsets of given string
// I / P : = "abc" 
// O / P : = "", a, b, c, ab, ac, bc, abc

// T.C : O(n^2) 
//  int main()
//  {
//     string str;
//     cin>>str;
//     int n=str.length();
//     int i,j;
//     for(i=0;i<n;i++)
//     {
//         for(j=i+1;j<=n;j++)
//         {
//             cout<<str.substr(i,j-i)<<" ";
//         }
//     }
//     return 0;
//  }

// Bit Manipulation
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
void findsub( vector<vector<int>> &res , vector<int> nums , int i){
        int j = 0;
        vector<int>v;
        while(i>0){
            if((i&1)==1) v.push_back(nums[j]);
            j++;
            i = i>>1;
        }
        res.push_back(v);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        //here 2^n -1 (as starts from 0) == (1 << n) - 1
        for(int i = 0 ; i < (1<<n) ;i++){
            findsub(res,nums,i);
        }
        return res;
    }