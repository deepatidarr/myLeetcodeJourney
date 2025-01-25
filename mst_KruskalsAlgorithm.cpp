//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class disjointSet{
    vector<int> rank, parent;
public:
    disjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
            
        }
    }        
    
    int findUltParent(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);
        
        if(ult_u == ult_v) return; //they belong to the same component
        
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        } else if(rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        } else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
    
};

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int, pair<int,int>>> edges;
        for(int i=0; i<V; i++){
            for(auto &it: adj[i]){
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {u, v}});
            }
        } 
        
        disjointSet ds(V);
        sort(edges.begin(), edges.end());
        int edgeWt = 0;
        for(auto &it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltParent(u) != ds.findUltParent(v)){
                //they belong to different components and we have to add them to one
                edgeWt += wt;
                ds.unionByRank(u, v);
            }
        }
        return edgeWt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
