int Solution::solve(vector<int> &A, int k) {
    int n = A.size();
    unordered_map<int,int> mp;
    mp[0]++;
    int xr = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        xr = xr^A[i];
        int x = k^xr;
        ans += mp[x];
        mp[xr]++;
    }
    return ans;
}
