class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // prev1 i - 1
        // prev2 i - 2;
        int prev2, prev1, temp, result;
        prev2 = 0;
        prev1 = nums[0];
        result = nums[0];
        for ( int i = 1; i < n; i++ ){
            temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
            result = max(result, prev1);
        }

        return result;
    }
};
