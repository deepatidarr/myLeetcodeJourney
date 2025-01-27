class Solution {
private:
    void fun(vector<vector<int>>& res, vector<int> &ds, vector<int>& nums, int ind){
        if(ind == nums.size()){
            res.push_back(ds);
            return;
        }
        //not-pick
        fun(res, ds, nums, ind+1);
        //pick
        ds.push_back(nums[ind]);
        fun(res,ds,nums,ind+1);
        ds.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        fun(res, ds, nums, 0);
        return res;
    }
};
