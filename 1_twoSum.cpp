class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            st.insert({nums[i],i});
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            int x = target-nums[i];
            if(st.find(x)!=st.end() && i!=st[x]){
                res = {i,st[x]};
                break;
            }
        }
        return res;
    }
};
