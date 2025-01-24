class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int>& check, vector<vector<int>>& graph){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto& it: graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, check, graph)){
                    return true;
                }
            }
            if(pathVis[it]){ //cycle found
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> vis(n,0), pathVis(n,0), check(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, graph);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]) res.push_back(i);
        }
        return res;
    }
};
