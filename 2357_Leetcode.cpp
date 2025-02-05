class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0) continue;
            if(i==0 || nums[i] != nums[i-1]){
                ans++;
            }
        }
        return ans;
    }
};
