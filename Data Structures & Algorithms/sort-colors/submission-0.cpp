class Solution {
public:
    void sortColors(vector<int>& nums) {
        sortByNumber(nums, 1, sortByNumber(nums, 0, 0) );
    }

    int sortByNumber(vector<int>& nums, int num, int index) {
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] == num ){
                swap(nums[index], nums[i]);
                index++;
            }
        }

        return index;
    }
};