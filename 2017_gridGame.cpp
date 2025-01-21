class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans = LONG_MAX;
        int n = grid[0].size();
        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long botSum = 0;
        for(int i=0; i<n; i++){
            topSum -= grid[0][i];
            ans = min(ans, max(topSum,botSum));
            botSum += grid[1][i];
        }
        return ans;
    }
};
