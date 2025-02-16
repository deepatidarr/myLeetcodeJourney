class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string &word, int n, int m, int index){
        if(i<0 || i>=n || j<0 || j>=m) {
            return false;
        }

        if(index == word.size()) return true;

        if(board[i][j] != word[index]) return false;
        char ch = board[i][j];
        board[i][j] = '*';

        bool u = dfs(board, i+1, j, word, n, m, index+1);
        bool d = dfs(board, i-1, j, word, n, m, index+1);
        bool r = dfs(board, i, j+1, word, n, m, index+1);
        bool l = dfs(board, i, j-1, word, n, m, index+1);

        board[i][j] = ch; //backtracking step
        return u|d|r|l;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        if(n==1 && m==1 && word.size()==1 && board[0][0]==word[0]) return true;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, word, n, m, 0)) return true;
                }
            }
        }

        return false;
    }
};
