class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len=0;
        bool middle=false;
        unordered_map<string, int> M;
        string rev;
        // Count occurences of each word
        for (auto& word : words) 
            M[word]++;
    
        for (auto& [s, freq]: M) {
            rev = s;
            reverse(rev.begin(), rev.end());
            
            // If word is palindrome
            if(s == rev) {
                // If freq is even, then add all occurences into resultant string
                if(freq%2 == 0)
                    len += freq;
                // If freq is odd, then add maximum possible even number of occurences i.e., freq-1
                else {
                    len += freq-1;
                    middle = true;
                }
            } 
            // If word is not palindrome but reverse is present
            else if(M.count(rev))
                len += min(freq, M[rev]);
        }
        // If an extra palindrome is there, we can insert in the middle to make it a bigger palindrome
        return 2*(len + middle);
    }
};