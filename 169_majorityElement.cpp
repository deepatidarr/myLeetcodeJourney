class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int n = nums.size();
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt == 0){
                ele = nums[i];
                cnt = 1;
            }
        }
        return ele;
    }
};
