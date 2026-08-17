class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> chars(128, false);
        int result = 0, last = 0;
        for ( int i = 0; i < s.size(); i++ ){
            if ( chars[s[i]] ) {
                for ( int j = last; j <= i  ; j++ ){
                    chars[s[j]] = false;
                    if ( s[i] == s[j] ){
                        last = j + 1;
                        break;
                    }
                }
            }

            chars[s[i]] = true;
            result = max(result, i - last + 1);
        }

        return result;
    }
};
