class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> merged;
        int i=0; int j=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }
        while(i<n1) merged.push_back(nums1[i++]);
        while(j<n2) merged.push_back(nums2[j++]);

        int n = merged.size();
        // for(auto &i: merged){
        //     cout<<i<<" ";
        // }
        double ans=0;
        if(n&1) return merged[n/2];
        //cout<<merged[(n/2)-1]<<" "<<merged[n/2];
        ans = (merged[n/2]+merged[(n/2)-1])/2.0;
        ans *= 1.0;
        return ans;
    }
};
