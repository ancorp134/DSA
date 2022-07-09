//leetcode ==> https://leetcode.com/problems/coin-change/

#include<bits/stdc++.h>
using namespace std;
//TOP DOWN APPROACH
// int minCoins(int n,int coins[],int TypeofCoins,vector<int> dp)
// {
//     //base CAse
//     if(n==0)
//         return 0;
//         //already computed
//     if(dp[n]!=-1)
//         return dp[n];
//         //recursive case
//     int ans=INT_MAX;
//     for(int i=0;i<TypeofCoins;i++)
//     {
//         if(n>=coins[i])
//         {
//             int subProblem=minCoins(n-coins[i],coins,TypeofCoins,dp);
//                if(subProblem!=INT_MAX && subProblem+1<ans)  //to prevent from integer overflow
//                     ans=subProblem+1;
//         }
//     }
//     dp[n]=ans;
//     return ans;
// }

//BOTTOM UP APPROACH
int minCoins(int n,int coins[],int TypeofCoins)
{
    vector<int> dp(n+1,-1);
    
    dp[0]=0;  //0 n k liye 0 coins chia honge
    for(int i=1;i<=n;i++)
    {
        int ans=INT_MAX;
        for(int j=0;j<TypeofCoins;j++)
        {
            if(i>=coins[j])
            {
                if(dp[i-coins[j]]!=-1 && dp[i-coins[j]]+1<ans)
                    ans=dp[i-coins[j]]+1;
            }
        }
        dp[i]=ans;
    }
    return dp[n];
}

int main(){

    int N=15;
    int coins[]={1,7,10};
    vector<int>dp(100,-1);
    int TypeofCoins=sizeof(coins)/sizeof(coins[0]);
    // cout<<minCoins(N,coins,TypeofCoins,dp);
    cout<<minCoins(N,coins,TypeofCoins);
}