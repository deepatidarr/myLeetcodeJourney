//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<int>& arr, int i, int prev_idx, vector<vector<int>>& dp) {
        if (i == arr.size()) return 0;
        if (prev_idx != -1 && dp[i][prev_idx] != -1) return dp[i][prev_idx];
        
        int notPick = fun(arr, i + 1, prev_idx, dp);
        int pick = 0;
        if (prev_idx == -1 || arr[i] > arr[prev_idx]) {
            pick = arr[i] + fun(arr, i + 1, i, dp);
        }
        
        if (prev_idx != -1) dp[i][prev_idx] = max(pick, notPick);
        return max(pick, notPick);
    }
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum=0;
        int prev = INT_MIN;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fun(arr, 0, -1, dp);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxSumIS(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
