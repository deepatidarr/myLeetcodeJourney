class Solution {
private:
    bool isPossible(long long mid, vector<int> &candies, long long k){
        long long x = 0;
        for(int i = 0; i < candies.size(); i++){
            x += (candies[i] / mid);
        }
        return x >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        if (k == 0) return 0;  // Edge case: no children
        
        long long lo = 1, hi = *max_element(candies.begin(), candies.end());
        long long sum = 0;

        for(int i = 0; i < candies.size(); i++){
            sum += (1LL * candies[i]);
        }
        
        if(k > sum) return 0;  // If total candies are less than k, return 0
        
        long long ans = 0;
        while(lo <= hi){
            long long mid = lo + (hi - lo) / 2;
            if(isPossible(mid, candies, k)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
