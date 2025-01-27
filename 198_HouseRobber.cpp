class Solution {
private:
    int memo(int index, vector<int>& nums, vector<int> &dp){
        if(index==0) return nums[0];
        if(dp[index] != -1) return dp[index];
        int right = memo(index-1, nums, dp);
        int left = nums[index]; 
        if(index > 1) left += memo(index-2, nums, dp);

        return dp[index] = max(left, right);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return memo(n-1, nums, dp);
    }
};
