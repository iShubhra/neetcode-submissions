class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp = {};
        int result = 0, last = 0;
        for ( int i = 0; i < s.size(); i++ ){
            if ( mp.find(s[i]) != mp.end() ) {
                last = max(last, mp[s[i]] + 1);
            }

            mp[s[i]] = i;
            result = max(result, i - last + 1);
        }
        
        return result; 
    }
};
