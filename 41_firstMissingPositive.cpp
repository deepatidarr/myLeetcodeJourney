class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        set<int> s;
        for(int i=0; i<n; i++){
            if(nums[i]<0) continue;
            s.insert(nums[i]);
        }
        for(auto &it: s){
            if(it == ans){
                ans++;
            }
        }
        return ans;
    }
};
