class Solution {
public:
    bool detectCapitalUse(string word) {
        bool noCaps = true, onlyFirstCap = false, allCaps = true;
        int n = word.size();
        for(int i=0; i<n; i++) {
            if(isupper(word[i])) {
                noCaps = false;
                if(i == 0)
                    onlyFirstCap = true;
                else 
                    onlyFirstCap = false;
            } else 
                allCaps = false;
        }

        return noCaps || onlyFirstCap || allCaps;
    }
};