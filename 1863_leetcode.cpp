class Solution {
private:
    void findAll(vector<vector<int>> &res, vector<int> &tmp, vector<int>&nums, int i){
        if(i==-1){
            res.push_back(tmp);
            return;
        }

        //take case
        tmp.push_back(nums[i]);
        findAll(res, tmp, nums, i-1);
        tmp.pop_back();

        //not take
        findAll(res, tmp, nums, i-1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int n = nums.size();
        findAll(res, tmp, nums, n-1);
        
        int ans=0;
        for(auto &it: res){
            int xr = 0;
            for(auto &i: it){
                xr = xr^i;
            }
            ans += xr;
        }
        return ans;
    }
};
