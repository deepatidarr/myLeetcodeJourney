class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum=0, maxSum=INT_MIN, minSum=INT_MAX;
        for(int i=0; i<n; i++){
            sum += nums[i];
            maxSum = max(sum, maxSum);
            if(sum<0) sum = 0;
        } 
        sum=0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            minSum = min(sum, minSum);
            if(sum>0) sum = 0;
        }
       // cout<<maxSum;
        return max(maxSum, abs(minSum));
    }
};
