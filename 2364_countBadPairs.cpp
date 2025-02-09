class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]-i]++;
        }
        long long int totalPairs = (n*(n-1))/2;
        for(auto &it: mp){
            if(it.second > 1){
                long long x = it.second;
                totalPairs -= (x*(x-1))/2;
            }
        }
        return totalPairs;
    }
};
