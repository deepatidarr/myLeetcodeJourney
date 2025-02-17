class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); int i=0;

        while(i<n){
            int correctIndex = INT_MIN;
            if(nums[i] > 0) correctIndex = nums[i]-1;

            if(nums[i]>0 && nums[i]<n && nums[i]!=nums[correctIndex]){
                swap(nums[i], nums[correctIndex]);
            }
            else{
                i++;
            }
        }

        for(i=0; i<n; i++){
            if(nums[i] != i+1){
                return (i+1);
            }
        }
        return n+1;
    }
};
