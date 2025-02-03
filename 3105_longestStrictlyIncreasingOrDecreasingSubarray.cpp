class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int l1 = 1, l2 = 1;
        int m1 = -1, m2 = -1;
        for(int i=0; i<n-1; i++){
            //strictly increasing
            if(nums[i] < nums[i+1]){
                l1++;
            }
            else{
                l1 = 1;
            }
            m1 = max(m1,l1);
        }
        if(nums[n-2] < nums[n-2]) l1++; m1 = max(m1,l1);

        for(int i=0; i<n-1; i++){
            //strictly decreasing
            if(nums[i] > nums[i+1]){
                l2++;
            }
            else{
                l2 = 1;
            }
            m2 = max(m2,l2);
        }
        if(nums[n-2] > nums[n-2]) l2++; m2 = max(m2,l2);
        return max(m1,m2);
    }
};
