class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[0] = nums[0];
        int robCurrent, currentSkip, val, result;
        result = dp[0];
        for ( int i = 1; i < n; i++ ){
            val = 0;
            if ( i - 2 >= 0 ) {
                val = dp[i - 2];
            }
            robCurrent = nums[i] + val;
            currentSkip = dp[i - 1];
            dp[i] = max(robCurrent, currentSkip);
            result = max(result, dp[i]);
        }

        return result;
    }
};
