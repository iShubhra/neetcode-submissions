class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) m[num]++;

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& [num, freq] : m) bucket[freq].push_back(num);

        vector<int> res;
        for ( int i = bucket.size() - 1; i >= 0 ; i-- ){
            for ( int num : bucket[i] ) {
                if ( res.size() == k ) break;
                res.push_back(num);
            }
        } 

        return res;
    }
};
