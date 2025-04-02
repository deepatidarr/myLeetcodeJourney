class Solution {
private:
    int fun(vector<int> &coins, int amount, int i, vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];

        int notTake = fun(coins, amount, i-1, dp);
        int take = 0;
        if(amount >= coins[i]){
            take = fun(coins, amount-coins[i], i, dp);
        }
        return dp[i][amount] = (take+notTake);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return fun(coins, amount, n-1, dp);
        // if(ans==1e9) return -1;
        // return ans;
    }
};
