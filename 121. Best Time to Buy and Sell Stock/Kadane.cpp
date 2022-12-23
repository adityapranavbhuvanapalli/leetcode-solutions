class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit=0, minimum=INT_MAX;
        
        for(auto& price: prices) {
            minimum = min(minimum, price);
            maxProfit = max(maxProfit, price - minimum);
        }
        
        return maxProfit;
    }
};