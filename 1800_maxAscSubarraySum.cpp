class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int sum = 0;
        int prev = -1;
        for(int i=0; i<n; i++){
            if(nums[i] > prev){
                sum += nums[i];
            }
            else{
                sum = nums[i];
            }
            prev = nums[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};
