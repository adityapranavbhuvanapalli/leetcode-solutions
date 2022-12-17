class Solution {
public:
    string makeGood(string s) {
        string stack = "";
        int n = s.size();
        for(int i=0; i<n; i++) {
            // Push the char into stack
            stack += s[i];         
            while(stack.size() && abs(stack.back()-s[i+1]) == 32) {
                // Pop if the char on top is equal to next char in s
                stack.pop_back(); 
                i++;  
            }
        }

        return stack;
    }
};