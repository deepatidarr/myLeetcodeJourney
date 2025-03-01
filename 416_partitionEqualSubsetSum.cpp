class Solution {
private:
    int findTarget(vector<int> &nums, int index, int target, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(index==0) return (nums[0]==target);
        
        if(dp[index][target] != -1) return dp[index][target];

        int pick = 0;
        if(nums[index] <= target){
            pick = findTarget(nums, index-1, target-nums[index], dp);
        }
        int notPick = findTarget(nums, index-1, target, dp);

        return dp[index][target]=(pick|notPick);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum&1) return false;
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return findTarget(nums, n-1, target, dp);
    }
};
