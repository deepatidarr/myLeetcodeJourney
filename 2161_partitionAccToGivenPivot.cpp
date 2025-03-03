class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res;
        int pcount=0;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                res.push_back(nums[i]);
            }
            else if(nums[i]==pivot) pcount++;
        }
        while(pcount--) res.push_back(pivot);
        for(int i=0; i<n; i++){
            if(nums[i]>pivot) res.push_back(nums[i]);
        }
        return res;
    }
};
