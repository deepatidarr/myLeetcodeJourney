class Solution {
    const int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [currDist, u] = pq.top(); pq.pop();

            if(currDist > dist[u]) continue;

            for(auto& [v, wt] : adj[u]){
                long long newDist = currDist + wt;

                if(newDist < dist[v]){
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } else if(newDist == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
