class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto& it: nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto& it: mp){
            pq.push({it.second, it.first});
        }
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
