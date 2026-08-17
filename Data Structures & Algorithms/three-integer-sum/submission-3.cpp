class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>>m;
        sort(nums.begin(), nums.end());

        int n = nums.size(), left, right, value;

        for ( int i = 0; i < n; i++ ){
            left = i, right = n - 1;
            while (left < right) {
                value = -(nums[left] + nums[right] - 0);
                auto it = lower_bound(nums.begin() + left + 1, nums.begin() + right, value);
                if (it != nums.begin() + right && *it == value) {
                    m.insert({nums[left], value, nums[right]});
                }

                right--;
            }
        }

        for ( vector<int> arr : m) res.push_back(arr);
        return res;
    }
};