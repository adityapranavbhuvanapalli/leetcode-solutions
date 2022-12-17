class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j]!='.' && !safe(board, i, j, board[i][j]))
                    return false;
            }
        }
        return true;
    }
    
    bool safe(vector<vector<char>>& board, int r, int c, char ch) {
        // Check horizontal and vertical
        int sr, sc;
        for(int i=0; i<9; i++) {
            if(board[i][c]==ch && i!=r)
                return false;
            if(board[r][i]==ch && i!=c)
                return false;
        }
            
        // Check square
        if(r<3) sr=0;
        else if(r<6) sr=3;
        else sr=6;
        
        if(c<3) sc=0;
        else if(c<6) sc=3;
        else sc=6;
         
        for(int i=sr; i<sr+3; i++)
            for(int j=sc; j<sc+3; j++)
                if((i!=r || j!=c) && board[i][j]==ch)
                    return false;
        
        return true;
    }
};