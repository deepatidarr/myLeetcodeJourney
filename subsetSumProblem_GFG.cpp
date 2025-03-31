//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<int> &arr, int sum, int i, vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(i==0){
            if(sum==arr[i]) return 1;
            return 0;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int notPick = fun(arr, sum, i-1, dp);
        int pick = 0;
        if(arr[i] <= sum){
            pick = fun(arr, sum-arr[i], i-1, dp);
        }
        
        return dp[i][sum] = pick|notPick;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (1e4+1, -1));
        return fun(arr, sum, n-1, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
