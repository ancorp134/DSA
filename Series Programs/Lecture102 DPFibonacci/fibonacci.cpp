// codestudio ==> 

#include<bits/stdc++.h>
using namespace std;


int fib(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
//RECURSION + MEMOIZATION  (tOP DOWN)
    // vector<int>dp(n+1,-1);
    // cout<<fib(n,dp)<<endl;

//TABULATION (BOTTOM UP)
    // vector<int>dp(n+1,-1);
    // dp[0]=0;
    // dp[1]=1;
    // for(int i=2;i<=n;i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n]<<endl;

//SPACE OPTIMIZED
    int a=0,b=1,c;
    cout<<a<<" "<<b<<" ";
    for(int i=2;i<n;i++){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    return 0;
}