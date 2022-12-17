class Solution {
public:
    int romanToInt(string s) {
        int top, val;
        map<char, int> ref;
        ref['I'] = 1;
        ref['V'] = 5;
        ref['X'] = 10;
        ref['L'] = 50;
        ref['C'] = 100;
        ref['D'] = 500;
        ref['M'] = 1000;

        vector<int> stack;
        for(auto& ch: s) {
            val = ref[ch];
            top = stack.size() ? stack.back() : 0;
            if(top >= val)
                stack.push_back(val);
            else {
                if(stack.size()) 
                    stack.pop_back();
                stack.push_back(val - top);
            }
        }

        return reduce(stack.begin(), stack.end());

    }
};