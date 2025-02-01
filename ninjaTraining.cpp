// PRBLEM LINK: https://www.naukri.com/code360/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
// 2D DP PROBLEM
//MEMOIZATION APPROACH

int fun(vector<vector<int>> &points, int index, int last, vector<vector<int>>& dp){
    if(index == 0){
        int maxi = -1;
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[index][last] != -1) return dp[index][last];
    int maxi = -1;
    for(int i=0; i<3; i++){
        if(i!=last){
            maxi = max(maxi, points[index][i]+fun(points, index-1, i, dp));
        }
    }
    return dp[index][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int last = 3;
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return fun(points, n-1, last, dp);
}
