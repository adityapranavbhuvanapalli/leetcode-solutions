class Solution {
public:
    struct TrieNode {
        string word;
        vector<TrieNode*> child;
        TrieNode(): word(""), child(vector<TrieNode*>(26, NULL)) {}
    };
    
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word: words) {
            TrieNode* curr = root;
            for (char ch: word) {
                int i = ch - 'a';
                if (!curr->child[i]) 
                    curr->child[i] = new TrieNode();
                curr = curr->child[i];
            }
            curr->word = word;  // Saving the word
        }
        return root;
    }

    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        m = board.size(), n = board[0].size();

        TrieNode* root = buildTrie(words);
        for(int i=0; i<m; i++) 
            for(int j=0; j<n; j++) 
                search(board, i, j, root, res);
        return res;
    }
    
    void search(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& res) {
        char ch = board[i][j];
        if(ch == '#' || curr->child[ch - 'a'] == NULL) 
            return;

        curr = curr->child[ch - 'a'];
        if (curr->word != "") {
            res.push_back(curr->word);
            curr->word = "";
        }

        // Backtrack
        board[i][j] = '#';
        if(i > 0) search(board, i - 1, j , curr, res); 
        if(j > 0) search(board, i, j - 1, curr, res);
        if(i < m-1) search(board, i + 1, j, curr, res); 
        if(j < n-1) search(board, i, j + 1, curr, res); 
        board[i][j] = ch;
    }
};