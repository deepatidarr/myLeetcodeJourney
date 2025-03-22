class Solution {
private:
    void dfs(vector<vector<int>>& adj, vector<int> &vis, int &e, int &nodes, int i){
        nodes++;
        vis[i] = 1;
        for(int &nbr: adj[i]){
            e++;
            if(!vis[nbr]){
                dfs(adj, vis, e, nodes, nbr);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cc=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int e=0, nodes=0;
                dfs(adj, vis, e, nodes, i);

                if(e == nodes*(nodes-1)) cc++;
            }
        }
        return cc;
    }
};
