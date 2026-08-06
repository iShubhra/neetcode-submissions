class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftArr(nums.size());
        vector<int> rightArr(nums.size());
        vector<int> resultArr(nums.size());

        leftArr[0] = nums[0];
        rightArr[nums.size() - 1] = nums[nums.size() - 1];

        for ( int left = 1; left < nums.size(); left++) {
            leftArr[left] = leftArr[left - 1] * nums[left]; 
        }

        for ( int right = nums.size() - 2; right >= 0;  right-- ) {
            rightArr[right] = rightArr[right + 1] * nums[right]; 
        }

        resultArr[0] = rightArr[1];
        resultArr[nums.size() - 1] = leftArr[nums.size() - 2];

        for ( int i = 1; i < nums.size() - 1; i++ ){
            resultArr[i] = leftArr[i - 1] * rightArr[i + 1];
        }

        return resultArr;
    }
};
