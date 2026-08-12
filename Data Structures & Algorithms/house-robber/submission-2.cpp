class Solution {
public:
    unordered_map<int, int>m;
    int rob(vector<int>& nums) {
        int result = 0;
        for ( int i = 0; i < nums.size(); i++ ){
            auto it = m.find(i);
            if ( it != m.end() ){
                result = max(it->second, result);
            }else {
                result = max(result, robHouse(nums, i, nums[i]));
            }
        }

        return result;
    }

    int robHouse(vector<int>& nums, int index, int robAmount) {
        auto it = m.find(index);
        if ( it != m.end() ) return it->second + robAmount;

        int result = robAmount, maxValue ;
        for ( int i = index + 2; i < nums.size(); i++ ){
            auto it = m.find(i);
            if ( it != m.end() ){
                maxValue = it->second + robAmount;
            }else {
                // i th max value maxValue = robAmount
                // total will be robAmout + m[i]

                maxValue =  robHouse(nums, i , robAmount + nums[i]);
                // ith max value
                int ithMaxValue = maxValue - robAmount;
                m[i] = ithMaxValue;
            }
            result = max(result, maxValue);
        }

        return result;
    }
};
