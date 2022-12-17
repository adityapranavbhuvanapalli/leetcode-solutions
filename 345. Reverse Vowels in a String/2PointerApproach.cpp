class Solution {
public:
    string reverseVowels(string s) {
        char tmp;
        // 2 Pointer approach
        int l=0, r=s.size()-1;
        while(l<r) {
            // If both s[l] and s[r] are vowels, then swap the vowels
            if(isVowel(s[l]) && isVowel(s[r])) {
                tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
                l++;
                r--;
            } 
            // If either is not a vowel, then increment l and r pointers
            else {
                if(!isVowel(s[l]))
                    l++;
                if(!isVowel(s[r]))
                    r--;
            }            
        }
        return s;
    }

    // Function to determine if a char ch is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};