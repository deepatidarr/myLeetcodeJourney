class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                //bool flag = false;
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1;
                int r = n-1;
                while(l<r){
                    long long int sum = nums[i];
                    sum += nums[j]; sum += nums[l]; sum += nums[r];
                    if(sum == target){
                        //flag = true;
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++; r--;
                        while(l<n && nums[l]==nums[l-1]) l++;
                        while(r>l && nums[r]==nums[r+1]) r--;
                    }
                    else if(sum < target){
                        l++;
                    }
                    else r--;
                }
                //if(flag) break;
            }
        }
        return res; 
    }
};
