class StockSpanner {
public:
    vector<pair<int, int>> stack;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(stack.size() && stack.back().first <= price) {
            span += stack.back().second;
            stack.pop_back();
        }
        stack.push_back({price, span});        
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */