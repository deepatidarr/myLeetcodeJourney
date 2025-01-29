class disJointSet{
public:
    vector<int> parent, rank;
    disJointSet(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i] = i;
        rank.resize(n+1, 0);
    }
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    bool unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return true;
        if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else if(rank[pv] > rank[pu]){
            parent[pu] = pv;
        }
        else{
            parent[pu] = pv;
            rank[pu]++;
        }
        return false;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        disJointSet ds(n);
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            if(ds.unionByRank(u, v)){
                ans = {u,v};
                //return ans;
            }
        }
        return ans;
    }
};
