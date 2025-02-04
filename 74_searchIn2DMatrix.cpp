class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo=0, hi=n-1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] > target){
                hi = mid-1;
            }
            else {
                lo = mid+1;
            }
        } 
        if(hi < 0) return false;
        lo = 0; int newHi=m-1;
        while(lo <= newHi){
            int mid = (lo+newHi)>>1;
            if(matrix[hi][mid] == target) return true;
            if(matrix[hi][mid] > target){
                newHi = mid-1;
            }
            else {
                lo = mid+1;
            }
        } 
        return false;
    }
};
