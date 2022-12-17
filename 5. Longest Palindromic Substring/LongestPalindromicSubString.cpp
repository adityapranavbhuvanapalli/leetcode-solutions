class Solution {
public:
    int max=1, start=0;
    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0; i<n-1; i++) {
            checkPalindrome(s, i, i, n);
            if(s[i]==s[i+1])
                checkPalindrome(s, i, i+1, n);
        }
        return s.substr(start,max);
    }
    
    void checkPalindrome(string s, int l, int r, int n) {
        while(l>0 && r<n-1 && s[l-1]==s[r+1]) {
            l--;
            r++;
        }
        int len=r-l+1;
        if(max<len){
            max=len;
            start=l;
        }
    }
};