//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(vector<int> &val, vector<int> &wt, int W, int i, vector<vector<int>> &dp){
        if(i==0){
            if(W >= wt[i]){
                return val[i];
            }
            return 0;
        }
        if(dp[i][W] != -1) return dp[i][W];
        int pick = INT_MIN;
        if(wt[i] <= W){
            pick = val[i] + fun(val, wt, W-wt[i], i-1, dp);
        }
        int notPick = fun(val, wt, W, i-1, dp);
        
        return dp[i][W] = max(pick, notPick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (1e3+1, -1));
        return fun(val, wt, W, n-1, dp);
        //return ans;
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
