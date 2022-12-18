class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0), stack;
        
        for(int i=n-1; i>=0; i--){
            while(stack.size() && temperatures[stack.back()] <= temperatures[i])
                stack.pop_back();
                
            answer[i] = stack.size() ? stack.back()-i : 0;
            stack.push_back(i);
        }
        return answer;
    }
};