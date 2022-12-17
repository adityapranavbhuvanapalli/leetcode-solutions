class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string v="";
        int n=s.length(), max=0, l=0,r=0, t;
        
        if(n==1)
            return 1;
        
        while(r<n) {
            t=v.find(s[r]);
            if(t==-1) {
                v+=s[r];
                r++;
            } else {
                v="";
                if(max<r-l)
                    max=r-l;
                l++;
                r=l;
            }
        }
        
        t=v.length();
        return t>max ? t : max; 
    }
    
};