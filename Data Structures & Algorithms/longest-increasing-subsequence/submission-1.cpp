class Solution {
public:
    unordered_map<int, int> m;
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        for ( int i = 0; i < nums.size(); i++ ){
            auto it = m.find(i);
            if ( it != m.end() ) {
                result = max(result, it->second);
            }else {
                result = max(result, maxSubSequence(nums, i, 1));
            }
        }

        return result;
    }

    int maxSubSequence(vector<int>& nums, int index, int countSequence) {
        int maxSequence = countSequence, value;
        if ( index + 1 > nums.size() ) return maxSequence;

        for ( int i = index + 1; i < nums.size(); i++ ){
            if ( nums[i] > nums[index] ) {
                auto it = m.find(i);
                if ( it != m.end() ) {
                    maxSequence = max(maxSequence, it->second + countSequence);
                }else {
                    value = maxSubSequence(nums, i, countSequence + 1);
                    m[i] = value - countSequence;
                    maxSequence = max(maxSequence , value);
                }
            }
        }
        
        return maxSequence;
    }
};
