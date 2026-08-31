class Solution {
public:
    int rob(vector<int>& dp, vector<int>& nums, int idx) {
        if ( idx < 0 ) return 0;
        if ( dp[idx] != -1 ) return dp[idx];
        int robCurrent = nums[idx] + rob(dp, nums, idx - 2);
        int currentSkip = rob(dp, nums, idx - 1);
        return dp[idx] = max(robCurrent, currentSkip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return rob(dp, nums, n - 1);
    }
};
