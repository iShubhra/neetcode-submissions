class Solution {
public:
    int rob(vector<int>& dp, vector<int>& nums, int idx) {
        if ( idx >= nums.size() ) return 0;
        if ( dp[idx] != -1 ) return dp[idx];
        int result = 0;
        for ( int i = idx; i < nums.size(); i++) {
            int nextRob = rob(dp, nums, i + 2);
            result = max(result, max(nextRob, nums[i] + nextRob));
        }

        return dp[idx] = result;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        int result = nums[0];
        for ( int i = 0; i < n; i++ ) result = max(result, rob(dp, nums, i));
        return result;
    }
};
