class Solution {
public:
    int solve(vector<int>& nums, int l, int r) {
        int prev = 0;
        int curr = 0;
        int next;

        for ( int i = l; i <= r; i++ ){
            next = max(nums[i] + prev, curr);
            prev = curr;
            curr = next;
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1 ) return nums[0];
        return max(
            solve(nums, 0, n - 2),
            solve(nums, 1, n - 1)
        );
    }
};
