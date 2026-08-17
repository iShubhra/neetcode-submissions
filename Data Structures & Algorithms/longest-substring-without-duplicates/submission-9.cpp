class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int result = 0, l = 0;
        for ( int i = 0; i < s.size(); i++ ){
			mp[s[i]]++;
			while (l < i && mp[s[i]] > 1) {
				mp[s[l]]--;
				l++;
			}

			result = max(result, i - l + 1);
        }

        return result;
    }
};
