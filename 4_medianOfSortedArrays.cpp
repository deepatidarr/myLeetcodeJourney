//MAX OPTIMISED SOLUTION
// TIME COMPLEXITY - O(LOG(n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        //assuming n1 is the smaller array.
        int take = (n+1)>>1;
        int lo=0, hi=n1;
        while(lo <= hi){
            int mid1 = (lo+hi)>>1;
            int mid2 = take-mid1;
            int l1 = INT_MIN; int l2=l1;
            int r1 = INT_MAX; int r2=r1;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 > 0) l1 = nums1[mid1-1];
            if(mid2 > 0) l2 = nums2[mid2-1];

            if(l1 <= r2 && l2 <= r1){ //valid symmtery!!!
                if(n&1) return max(l1,l2);
                return (max(l1,l2)+min(r1,r2))/2.0;
            }

            else if(l1 > r2) hi = mid1-1;
            else lo = mid1+1;
        }
        return 0.0;
    }
};
