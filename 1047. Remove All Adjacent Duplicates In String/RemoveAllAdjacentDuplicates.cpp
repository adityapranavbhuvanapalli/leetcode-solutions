class Solution {
public:
    string removeDuplicates(string s) {
        string stack = "";
        int n=s.size();
        for(int i=0; i<n; i++) {
            stack += s[i];
            while(stack.size() && stack.back() == s[i+1]) {
                stack.pop_back();
                i++;
            }
        }
        return stack;
    }
};