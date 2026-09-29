class Solution {
public:
     int sol(vector<int>& nums, int i, vector<int>& memo) {
        if (i >= nums.size()) return 0;
        if (memo[i] != -1) return memo[i];
        return memo[i] = max(sol(nums, i + 1, memo), nums[i] + sol(nums, i + 2, memo));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        vector<int>a,b;
        for(int i=0;i<n-1;i++)a.push_back(nums[i]);
        for(int i=1;i<n;i++)b.push_back(nums[i]);
        return max(sol(a,0,dp1),sol(b,0,dp2));
    }
};
