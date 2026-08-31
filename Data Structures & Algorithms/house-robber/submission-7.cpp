class Solution {
public:
    int rob(vector<int>& dp, vector<int>& nums, int idx) {
        if ( idx >= nums.size() ) return 0;
        if ( dp[idx] != -1 ) return dp[idx];
        int result = 0;

        for ( int i = idx; i < nums.size(); i++) {
            int val = rob(dp, nums, i + 2);
            dp[i] = max(nums[i] + val, max(nums[i], val));
            result = max(result, dp[i]);
        }

        return result;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return rob(dp, nums, 0);
    }
};
