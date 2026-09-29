class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        return climbStairs1(n,dp);
    }
    
    int climbStairs1(int n,vector<int>&dp) {
        if(n<=1)return 1;
        if(dp[n]!=0) return dp[n];
        else return dp[n]=climbStairs1(n-1,dp)+climbStairs1(n-2,dp);
    }
};
