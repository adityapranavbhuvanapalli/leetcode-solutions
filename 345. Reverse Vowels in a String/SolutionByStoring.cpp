class Solution {
public:
    string reverseVowels(string s) {
        int k=0;
        string vowels="";

        // Add all the vowels into a string 'vowels'
        for(auto ch: s) 
            if(isVowel(ch))
                vowels += ch;

        // Reverse the vowels
        reverse(vowels.begin(), vowels.end());

        // Replace the vowels in s with the reversed vowels 
        for(auto &ch: s) 
            if(isVowel(ch))
                ch = vowels[k++];

        return s;
    }

    // Function to determine if a char ch is a vowel
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};