class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) st.push(nums[i]);
        
        int i = n-1;
        while((i>=0) && (st.size()>0)){
            while(st.size() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.size()>0) {
                res[i] = st.top();
            }
            st.push(nums[i]);
            i--;
        }
        return res;
    }
};
