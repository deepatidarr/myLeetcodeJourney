class Solution {
private:
    void fish(vector<vector<int>>& grid, int i, int j, int &fishes, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]<=0) return;
        fishes += grid[i][j];
        grid[i][j] = -1;

        fish(grid, i+1, j, fishes, n, m);
        fish(grid, i-1, j, fishes, n, m);
        fish(grid, i, j+1, fishes, n, m);
        fish(grid, i, j-1, fishes, n, m);

        cout<<"fishes = "<<fishes<<endl;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(); int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0){
                    int fishes = 0;
                    fish(grid, i, j, fishes, n, m);
                    ans = max(ans, fishes);
                }
            }
        }
        return ans;
    }
};
