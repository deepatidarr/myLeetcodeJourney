//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    int upperBound(vector<int>& arr, int up){
        int lo=0, hi=arr.size()-1;
        int ans = arr.size();
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(arr[mid] > up){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
    int fun(vector<vector<int>> &mat, int mid){
        int ans = 0;
        for(int i=0; i<mat.size(); i++){
            ans += upperBound(mat[i], mid);
        }
        return ans;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int lo=INT_MAX, hi=INT_MIN;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; j++){
                lo = min(lo, mat[i][j]);
                hi = max(hi, mat[i][j]);
            }
        }
        int nums = (n*m)/2;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            //what we want to do now is to see how many elements in the matrix are LESS THAN mid
            int findNum = fun(mat, mid);
            if(findNum <= nums){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return lo;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
