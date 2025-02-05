class Solution {
private:
    int specialDfs(vector<vector<char>> &board, int i, int j, int n, int m, bool &flag){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != 'X') {
            return 0;
        }
        board[i][j] = '!';

        int right = specialDfs(board, i, j+1, n, m, flag);
        int left = specialDfs(board, i, j-1, n, m, flag);
        int up = specialDfs(board, i-1, j, n, m, flag);
        int down = specialDfs(board, i+1, j, n, m, flag);

        vector<int> v = {left, right, up, down};
        int ct=0;
        for(int i=0; i<4; i++){
            if(v[i] > 0) ct++;
            cout<<v[i]<<" ";
        }cout<<endl;
        if(ct > 1) {
            flag = false;
        }
        return (left+right+up+down+1);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='X'){
                    bool flag = true;
                    int tmp = specialDfs(board, i, j, n, m, flag);
                    if(flag == true) ans++;
                }
            }cout<<endl;
        }
        return ans;
    }
};
