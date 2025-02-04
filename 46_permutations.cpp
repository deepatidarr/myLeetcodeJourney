class Solution {
private:
    void fun(vector<vector<int>> &res, vector<int> &nums, int index){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            fun(res, nums, index+1);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        fun(res, nums, 0);
        return res;
    }
};
