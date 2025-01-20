class Solution {
private:
    queue<vector<int>> q; 
    vector<pair<int,int>> moves = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    bool isValid(vector<vector<int>>& grid, int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1) {
            return true;
        }
        return false;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vector<int> v = {i,j,0};
                    q.push(v);
                }
            }
        }
        while(q.size()){
            auto v = q.front();
            q.pop();
            int i=v[0], j=v[1], level=v[2];
            ans = max(ans,level);
            for(auto &mov: moves){
                if(isValid(grid, i+(mov.first), j+(mov.second), n, m)){
                    q.push({mov.first+i, mov.second+j,level+1});
                    grid[mov.first+i][mov.second+j] = -2;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
