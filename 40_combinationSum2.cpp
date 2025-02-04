class Solution {
private:
    void fun(vector<vector<int>> &res, vector<int> &ds, vector<int> &can, int index, int target){
        if(target == 0){
            res.push_back(ds);
        }

        for(int i=index; i<can.size(); i++){
            if(i!=index && can[i]==can[i-1]){
                continue;
            }
            if(target-can[i] >= 0){
                ds.push_back(can[i]);
                fun(res, ds, can, i+1, target-can[i]);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(can.begin(), can.end());
        fun(res, ds, can, 0, target);
        return res;
    }
};
