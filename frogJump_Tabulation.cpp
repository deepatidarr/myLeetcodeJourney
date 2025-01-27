#include <bits/stdc++.h> 
//TABULATION APPROACH!

// int solution(int n, vector<int>& heights, int index, vector<int>& dp){
//     if(index == 0) {
//         return 0;
//     }
//     if(dp[index] != -1) return dp[index];
//     int left = solution(n, heights, index-1, dp) + abs(heights[index]-heights[index-1]);
//     int right = INT_MAX;
//     if(index>1) right = solution(n, heights, index-2, dp) + abs(heights[index]-heights[index-2]);

//     return dp[index] = min(left, right);
// }

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,-1); //step 1
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(left, right);
    }
    return dp[n-1];
    //return solution(n, heights, n-1, dp);
}
