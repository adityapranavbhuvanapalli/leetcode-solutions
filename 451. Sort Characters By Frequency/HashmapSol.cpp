class Solution {
public:
    string frequencySort(string s) {
        // Store the frequency of each character
        unordered_map<char, int> freq;
        for(auto& ch: s)
            freq[ch]++;

        // Sorting map based on values
        // Since sorting a map is not possible
        // Convert it into a vector of pairs and then sort
        vector<pair<char, int>> V(freq.begin(), freq.end());
        sort(V.begin(), V.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        string res="";
        for(auto& v: V)
            for(int i=0; i<v.second; i++)
                res += v.first;

        return res;

    }
};