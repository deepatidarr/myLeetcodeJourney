class Solution {
private:
    void dfs(int curr, vector<vector<int>> &res, vector<vector<int>> &graph, vector<int> &tmp){
        if(curr == graph.size()-1){
            res.push_back(tmp);
            return;
        }

        for(auto &nbr: graph[curr]){
            tmp.push_back(nbr);
            dfs(nbr, res, graph, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();
        vector<int> tmp; tmp.push_back(0);
        dfs(0, res, graph, tmp);
        return res;
    }
};
