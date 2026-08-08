class Solution {
public:
    int count = 0;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int>arr;
        dfs(result, arr, nums, target, 0, 0);
        cout << count << endl;
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& arr, vector<int>& nums, int target, int sum, int idx) {
        if ( sum > target ){
            return;
        }

        if ( sum == target ) {
            result.push_back(arr);
            return;
        }

        for ( int i = idx; i < nums.size(); i++ ){
            if ( nums[i] + sum > target ) {
                continue;
            }

            arr.push_back(nums[i]);
            sum += nums[i];
            dfs(result, arr, nums, target, sum, i);
            sum -= nums[i];
            arr.pop_back();
        }
    }
};
