class Solution {
private:
    void dfs(vector<vector<int>> &grid, int i, int j, queue<pair<int,int>> &q, int &n){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return;
        grid[i][j] = -1; // we are marking the first island

        q.push({i,j});

        dfs(grid, i+1, j, q, n);
        dfs(grid, i-1, j, q, n);
        dfs(grid, i, j+1, q, n);
        dfs(grid, i, j-1, q, n);
    }

    vector<pair<int,int>> moves = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };
    bool isValid(int i, int j, int n){
        if(i>=0 && i<n && j>=0 && j<n) return true;
        return false;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();    
        queue<pair<int,int>> q;
        bool found = false;
        for(int i=0; i<n && !found; i++){
            for(int j=0; j<n && !found; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, q, n);
                    found = true;
                }
            }
        }
        int steps = 0;
        while(q.size()){
            int sz = q.size();
            while(sz--){
                auto [x, y] = q.front(); q.pop();
                for(auto [dx,dy]: moves){
                    if(isValid(x+dx, y+dy, n)){
                        int nx = x+dx; int ny = y+dy;
                        
                        if(grid[nx][ny]==1) return steps;
                        
                        if(grid[nx][ny] == 0){
                            grid[nx][ny] = -1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
