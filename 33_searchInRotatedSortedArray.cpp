class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(nums[mid] == target) return mid;
            if(nums[lo]<=nums[mid]){ //left half sorted
                if(target<nums[mid] && target>=nums[lo]) hi = mid-1;
                else lo = mid+1;
            }
            else{ //right half sorted
                if(target>nums[mid] && target<=nums[hi]){
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        return -1;
    }
};
