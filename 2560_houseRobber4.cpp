class Solution {
private:
    bool isPossible(vector<int> &nums, int mid, int k){
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid){
                count++; i++;
            }
        }
        return count>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(isPossible(nums, mid, k)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
