class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(nums[mid]>0){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        int pos = n-lo;
        int tmp=lo-1;
        while(tmp>=0 && nums[tmp]==0){
            tmp--;
        }
        int neg = tmp+1;
        return max(pos,neg);
    }
};
