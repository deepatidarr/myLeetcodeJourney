class Solution {
private:
    void fun(vector<vector<int>>& res, vector<int>& ds, vector<int>& nums, int index){
        res.push_back(ds);

        for(int i=index; i<nums.size(); i++){
            if(i!=index && nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            fun(res, ds, nums, i+1);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ds;
        fun(res, ds, nums, 0);
        return res;
    }
};
