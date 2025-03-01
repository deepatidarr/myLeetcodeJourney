int minSubsetSumDifference(vector<int>& nums, int nn)
{
		int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum+=nums[i];

        vector<vector<bool>> dp(n, vector<bool>(sum+1, false)); // we gonna tabulate
        // the last row of the dp array will tell us if a given sum (from 1->sum) is a possibility
        // or no. Based on this, we can do this problem and find the minimum difference of sums!
        for(int i=0; i<n; i++) dp[i][0] = true; // a sum of zero is always possible;
        dp[n-1][sum] = true; // the sum of all the elements is also possible
        for(int i=1; i<n; i++){
            for(int t=1; t<=sum; t++){
                bool pick = false;
                if(t>=nums[i]) pick = dp[i-1][t-nums[i]];
                bool notPick = dp[i-1][t];
                dp[i][t] = (pick|notPick);
            }
        }

        int ans = INT_MAX;
        //now we will only iterate the last row
        for(int i=0; i<=sum; i++){
            int a = i;
            int b = sum-i;
			if(dp[n-1][i])
            	ans = min(ans, abs(a-b));
        }
        return ans;
}
