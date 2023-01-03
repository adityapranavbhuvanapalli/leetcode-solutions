class Solution {
public:
    vector<vector<char>> res;
    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        backtrack(0, 0, board);
        board.clear();
        for(int i=0; i<9; i++)
            board.push_back(res[i]);
    }
    
    void backtrack(int r, int c, vector<vector<char>>& board) {
        r += (c==9);
        c %= 9;
        
        if(r==9) {
            for(int i=0; i<9; i++)
                res.push_back(board[i]);
            return;
        }
        
        if(board[r][c]!='.'){
            backtrack(r, c+1, board);
            return;
        }
        
        for(char k='1'; k<='9'; k++) {
            if(safe(board, r, c, k)) {
                board[r][c]=k;
                backtrack(r, c+1, board);
                board[r][c]='.';
            }
        }
    }
    
    bool safe(vector<vector<char>>& board, int r, int c, char ch) {
        // Check horizontal and vertical
        int sr, sc;
        for(int i=0; i<9; i++) {
            if(board[i][c]==ch)
                return false;
            if(board[r][i]==ch)
                return false;
        }
            
        // Check square
        sr = (r/3) * 3;
        sc = (c/3) * 3;
         
        for(int i=sr; i<sr+3; i++)
            for(int j=sc; j<sc+3; j++)
                if((i!=r || j!=c) && board[i][j]==ch)
                    return false;
        
        return true;
    }
};