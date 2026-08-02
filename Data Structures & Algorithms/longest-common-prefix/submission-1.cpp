class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        string str = strs[0];
        if ( strs.size() == 1 ){
            return str;
        }

        for ( int i = 0; i < str.size(); i++ ) {
            for ( int j = 1; j < strs.size(); j++ ){
                if ( ( strs[j].size() - 1 < i ) ||  ( str[i] != strs[j][i] ) ) {
                    return result;
                }
            }
            result.push_back(str[i]);
        }

        return result;
    }
};