class Solution {
public:
    map<char, string> M;
    unordered_set<string> strs;
    bool wordPattern(string pattern, string s) {
        int n = s.size(), pLen = pattern.size();
        vector<string> words;
        string w = "";

        // Extract words into vector of strings
        for(int i=0; i<=n; i++) {
            if(i==n || s[i] == ' ') {
                words.push_back(w);
                w = "";
            } else
                w += s[i];
        }

        // No. of words should be equal to no. of chars in pattern
        if(words.size() != pLen)
            return false;

        // Map chars to words
        for(int i=0; i<pLen; i++) {
            if(M.count(pattern[i]) == 0) {
                if(strs.insert(words[i]).second)
                    M[pattern[i]] = words[i];
                else 
                    return false;
            }
            else if(M[pattern[i]] != words[i])
                return false;
        }

        return true;
    }
};