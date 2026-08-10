class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>l(n);
        vector<int>r(n);
        vector<int>res(n);
        int prefix = 1, suffix = 1;
        int left = 0, right = n - 1;
        while (left < n) {
            l[left] = prefix;
            left++;
            prefix *= nums[left - 1];

            r[right] = suffix;
            right--;
            suffix *= nums[right + 1];
        }

        for ( int i = 0; i < n; i++ ) res[i] = l[i] * r[i];

        return res;
    }
};
