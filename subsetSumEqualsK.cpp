#include <bits/stdc++.h> 

int tryAll(vector<int> &arr, int target, int index, vector<vector<int>> &dp){
    if(target==0) return 1;
    if(index==0){
        if(target==arr[index]) return 1;
        return 0;
    }
    if(dp[index][target] != -1) return dp[index][target];
    int take=0;
    if(arr[index] <= target){
        take = tryAll(arr, target-arr[index], index-1, dp);
    }
    int notTake = tryAll(arr, target, index-1, dp);

    return dp[index][target] = (take | notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return tryAll(arr, k, n-1, dp);
}
