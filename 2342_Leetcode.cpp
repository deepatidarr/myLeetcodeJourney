class Solution {
private:
    int digitSum(int a){
        int sum = 0;
        while(a){
            sum += a%10;
            a /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int sum=0, ans=-1;
        vector<int> sums(83, -1);
        for(int i=0; i<n; i++){
            sum = digitSum(nums[i]);
            if(sums[sum] != -1){
                ans = max(ans, nums[i]+sums[sum]);
                sums[sum] = max(sums[sum], nums[i]);
            }
            else{
                sums[sum] = nums[i];
            }
        }
        return ans;
    }
};
