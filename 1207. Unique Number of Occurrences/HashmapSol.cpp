class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> count;
        unordered_set<int> uniq;

        for(auto& num: arr)
            count[num]++;

        for(auto& m: count)
            if(!uniq.insert(m.second).second)
                return false;

        return true; 
    }
};