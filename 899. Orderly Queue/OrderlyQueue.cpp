class Solution {
public:
    string orderlyQueue(string s, int k) {

        if(k > 1) {
            sort(s.begin(),s.end());
            return s;
        }
        
        int n = s.size();
        set<string> order;
        for(int i=0; i<n; i++)
            order.insert(s.substr(i, n) + s.substr(0, i));
        
        return *(order.begin());
    }
};