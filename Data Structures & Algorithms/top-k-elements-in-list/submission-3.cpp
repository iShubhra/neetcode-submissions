class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) m[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (auto const& [num, freq] : m ) pq.push({num, freq});

        vector<int> res;
        while (k && !pq.empty()){
            k--;
            res.push_back(pq.top().first);
            pq.pop();
        } 

        return res;
    }
};
