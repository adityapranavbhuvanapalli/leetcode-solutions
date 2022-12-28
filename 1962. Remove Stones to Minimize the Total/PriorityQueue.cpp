class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int maxPile, minStones = 0;

        // Add to priority queue
        for(auto& pile: piles)
            pq.push(pile);

        // GREEDY (Remove stones from pile with maximum stones)
        while(k-- > 0) {
            maxPile = pq.top();
            pq.pop();
            maxPile = ceil(maxPile/2.0);
            pq.push(maxPile);
        }

        // Sum up the remaining stones
        while(pq.size()) {
            minStones += pq.top();
            pq.pop();
        }

        return minStones;
    }
};