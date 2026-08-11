class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, prefixSum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for ( int i = 0; i < nums.size(); i++ ){
            prefixSum += nums[i];
            auto it = m.find(prefixSum - k);
            if ( it != m.end() ) result += it->second;
            m[prefixSum]++;
        }

        return result;
    }
};