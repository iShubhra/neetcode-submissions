class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n, 1);
        int prefix = 1, suffix = 1;
        int left = 0, right = n - 1;
        while (left < n) {
            res[left] = res[left] * prefix;
            left++;
            prefix *= nums[left - 1];

            res[right] = res[right] * suffix;
            right--;
            suffix *= nums[right + 1];
        }

        return res;
    }
};
