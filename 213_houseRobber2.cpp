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
        vector<int> tmp1, tmp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n-1; i++) tmp1.push_back(nums[i]);
        for(int i=1; i<n; i++) tmp2.push_back(nums[i]);
        vector<int> dp1(n,-1), dp2(n,-1);
        return max(memo(n-2, tmp1, dp1), memo(n-2, tmp2, dp2));
    }
};
