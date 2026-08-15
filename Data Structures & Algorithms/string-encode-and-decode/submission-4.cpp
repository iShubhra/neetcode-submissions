class Solution {
public:
    const string encodeStr = ":papa:";

    string encode(vector<string>& strs) {
        string res;
        int n = strs.size();

        if (n == 0) return "";

        for (int i = 0; i < n; i++) {
            res += strs[i] + encodeStr;
        }

        return res;
    }
    
    vector<string> decode(string s) {
        vector<string> result;
        if (s.empty()) return result;

        size_t start = 0;
        size_t pos;

        while ((pos = s.find(encodeStr, start)) != string::npos) {
            result.push_back(s.substr(start, pos - start));
            start = pos + encodeStr.length();
        }

        return result;
    }
};