class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int left = INT_MAX, right=INT_MAX, centre=dp[i+1][j];
                if(j>0) left = dp[i+1][j-1];
                if(j<n-1) right = dp[i+1][j+1];
                dp[i][j] = matrix[i][j] + min({left, centre, right});
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};
