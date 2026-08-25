class Solution {
public:
    bool canJump(vector<int>& nums) {
        int steps = nums[0];
        for ( int i = 1; i < nums.size(); i++ ){
            if ( steps == 0 ) return false;
            steps--;
            if ( steps < nums[i] ) {
                steps = nums[i];
            }
        }

        return true;
    }
};
