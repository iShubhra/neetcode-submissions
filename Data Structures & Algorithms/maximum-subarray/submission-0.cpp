class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], currentSum = result;
        for ( int i = 1; i < nums.size(); i++ ){
            currentSum = max(nums[i], currentSum + nums[i]);
            result = max(currentSum, result);
        }

        return result;
    }
};
