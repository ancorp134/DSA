// COUNT WAYS TO REACH NTH STAIRS
// https://leetcode.com/problems/climbing-stairs/submissions/

// MINIMUM COST CLIMBING STAIRS
//  https://leetcode.com/problems/min-cost-climbing-stairs/

#include <bits/stdc++.h>
using namespace std;
//T.C. O(n) S.C. O(n)+O(n)
// RECURSION + MEMOIZATION
class Solution{
public:
    int solve(vector<int> &cost, int n,vector<int> &dp){
        // BASE CASE
        if (n == 0) return cost[0];
        if (n == 1)  return cost[1];
        //step 3: if we have already calculated the value for this index, return it
        if(dp[n] != -1) return dp[n];
        //step 2 : calculate the value for this index
        dp[n] = cost[n] + min(solve(cost, n - 1,dp), solve(cost, n - 2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        //step 1 : initialize the dp array
        vector<int> dp(n+1,-1);
        int ans = min(solve(cost, n - 1,dp), solve(cost, n - 2,dp));
        return ans;
    }
};

//T.C. O(n) S.C. O(n)
// TABULATION
//  class Solution {
//  public:
//      int minCostClimbingStairs(vector<int>& cost) {
//          int n=cost.size();
//          int dp[n];
//          dp[0]=cost[0];
//          dp[1]=cost[1];
//          for(int i=2;i<n;i++)
//              dp[i]=min(dp[i-2],dp[i-1])+cost[i];

//         return min(dp[n-1],dp[n-2]);
//     }
// };