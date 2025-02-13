class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        int n = nums.size();
        for(auto &it: nums){
            pq.push(it);
        }
        int ans = 0;
        while(pq.size() > 1){
            if(pq.top() >= k){
                return ans;
            }
            ans++;
            long long int t1 = pq.top(); pq.pop();
            long long int t2 = pq.top(); pq.pop();
            long long int x = min(t1, t2);
            x *= (long long int)2;
            x += (long long int)max(t1, t2);
            cout<<"x = "<<x<<endl;
            pq.push(x);
        }
        return ans;
    }
};
