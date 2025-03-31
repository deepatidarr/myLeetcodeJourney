class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        for(auto &it: relations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> indegree(n+1, 0);
        for(auto &it: adj){
            for(auto &i: it){
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=1; i<=n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> dp(n+1, 0);
        for(int i=0; i<time.size(); i++){
            dp[i+1] = time[i];
        }
        while(q.size()){
            int node = q.front(); q.pop();
            
            for(auto &nbr: adj[node]){
                indegree[nbr]--;
                dp[nbr] = max(dp[nbr], time[nbr-1]+dp[node]);
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
