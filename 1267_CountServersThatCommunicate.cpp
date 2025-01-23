class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int,int> rows, cols;
        int total=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    rows[i]++;
                    cols[j]++;
                    total++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && rows[i]==1 && cols[j]==1){
                    --total;
                }
            }
        }
        return total;
    }
};
