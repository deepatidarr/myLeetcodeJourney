class Solution {
private:
    bool isSafe(int row, int col, vector<string> &board, int n){
        int r = row, c = col;
        while(r>=0 && c>=0){ // left-up diagonal
            if(board[r--][c--] == 'Q') return false;
        }
        r = row; c = col;
        while(c>=0){ // left side
            if(board[row][c--] == 'Q') return false;
        }

        r=row; c=col;
        while(r<n && c>=0){ //left-down diagonal
            if(board[r++][c--] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &res, vector<string> &board, int n, int col){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(res, board, n, col+1);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        solve(res, board, n, 0);
        return res;
    }
};
