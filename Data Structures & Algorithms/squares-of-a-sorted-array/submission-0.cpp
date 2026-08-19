class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        int left = 0, right = n - 1, idx = n - 1;
        while ( left <= right ){
            if ( nums[left] * nums[left] < nums[right] * nums[right] ) {
                res[idx] = nums[right] * nums[right];
                right--;
            }else {
                res[idx] = nums[left] * nums[left];
                left++;
            }
            idx--;
        }

        return res;
    }
};