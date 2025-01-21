class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        vector<int> res(n,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        res[src] = 0;
        pq.push({0,src}); // distance, node
        
        while(pq.size()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it: adj[node]){
                int node = it.first;
                int edgeWeight = it.second;
                
                if(dist+edgeWeight < res[node]){
                    res[node] = dist+edgeWeight;
                    pq.push({res[node],node});
                }
            }
        }
        
        return res;
    }
};
