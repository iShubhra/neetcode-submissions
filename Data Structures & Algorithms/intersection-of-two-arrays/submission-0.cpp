class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s;
        unordered_set<int>rs;
        for ( int num : nums1) s.insert(num);
        vector<int> res;
        for ( int num : nums2 ) {
            if ( s.contains(num) ) rs.insert(num);
        }
        for ( int num : rs ) res.push_back(num);
        return res;
    }
};