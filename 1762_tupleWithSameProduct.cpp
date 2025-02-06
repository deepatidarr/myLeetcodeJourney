class Solution {
private:
    int nC2(int n){
        return (n*(n-1))/2;
    }
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }      
        int ans = 0;
        for(auto &it: mp){
            ans += 8*(nC2(it.second));
        }
        return ans;
    }
};
