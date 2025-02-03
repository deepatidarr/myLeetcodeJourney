class Solution {
private:
    void fun(vector<vector<int>>& res, vector<int> &ds, vector<int>& can, int target, int index){
        if(index == can.size()){
            if(target==0){
                res.push_back(ds);
            }
            return;
        }

        if(target-can[index] >= 0){//pick condition
            ds.push_back(can[index]);
            fun(res, ds, can, target-can[index], index);
            ds.pop_back();
        }

        //not pick
        fun(res, ds, can, target, index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        fun(res, ds, can, target, 0);
        return res; 
    }
};
