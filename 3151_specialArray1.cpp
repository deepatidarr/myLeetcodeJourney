class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        bool ans = false;
        if(n==1) return true;;
        for(int i=1; i<n-1; i++){
            int x = nums[i-1];
            int y = nums[i+1];
            if(nums[i]&1){
                if(x%2!=0 || y%2!=0) return false;
            }
            else if(nums[i]%2==0){
                if(x%2==0 || y%2==0) return false;
            }
        }
        if((nums[0]%2==0 && nums[1]%2==0) ||(nums[0]&1 && nums[1]&1)) return false;
        if((nums[n-1]%2==0 && nums[n-2]%2==0) ||(nums[n-1]&1 && nums[n-2]&1)) return false;
        return true;
    }
};
