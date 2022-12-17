class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(), count = 0, vowel;
        for(int i=0; i<n; i++) {
            vowel = isVowel(s[i]);
            count += (i<n/2) ? vowel: -vowel;
        }

        return count == 0;
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ;
    }
};