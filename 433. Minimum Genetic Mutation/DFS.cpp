class Solution {
public:
    int res=INT_MAX;
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> mutations;
        string choices="ACGT";
        dfs(start, end, 0, bank, mutations, choices);
        return res==INT_MAX ? -1 : res;
    }

    void dfs(string s, string end, int n, vector<string>& bank, unordered_set<string>& mutations, string& choices) {
        if(s == end) {
            res = min(res, n);
            return;
        }

        for(int i=0; i<8; i++) {
            for(auto choice: choices) {
                if(s[i] == choice)
                    continue;
                char tmp = s[i];
                s[i] = choice;
                if(mutations.insert(s).second && find(bank.begin(), bank.end(), s) != bank.end())
                    dfs(s, end, n+1, bank, mutations, choices);
                s[i] = tmp;
            }
        }
    }
};