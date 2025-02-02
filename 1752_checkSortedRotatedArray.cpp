class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        int flag = 0;
        while(i<n){
            if(nums[i] >= nums[i-1]){
                i++;
            }
            else{
                flag = 1;
                break;
            }
        }
        //now i have the first break point
        while(flag && i<n-1){
            if(nums[i] <= nums[i+1]){
                i++;
            }
            else{
                return false;
            }
        }
        if(flag && nums[n-1] > nums[0]) return false;
        return true;
    }
};
