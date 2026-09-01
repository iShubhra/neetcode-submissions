class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0]; // i - 1
        int prev2 = 0; // i - 2
        int result = prev1;
        int temp;
        for ( int i = 1; i < nums.size() - 1; i++ ){
            temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
            result = max(result, prev1);
        }

        if ( nums.size() == 1 ) return result;

        prev1 = nums[1]; // i - 1
        prev2 = 0; // i - 2
        result = max(result, prev1);
        for ( int i = 2; i < nums.size(); i++ ){
            temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
            result = max(result, prev1);
        }

        return result;
    }
};
