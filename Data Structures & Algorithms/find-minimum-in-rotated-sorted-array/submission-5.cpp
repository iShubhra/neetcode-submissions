class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0], left = 0, right = nums.size() - 1, mid;
        while ( left <= right ) {
            mid = left + ( right - left ) / 2;
            result = min(result, nums[mid]);
            if ( nums[mid] > nums[right] ){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }

        return result;
    }
};
