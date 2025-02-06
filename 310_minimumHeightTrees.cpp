class Solution {
private:
    int findHt(vector<vector<int>> &adj, int src, vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({src,0});
        int len = -1;
        while(q.size()){
            int node = q.front().first;
            int level = q.front().second;
            q.pop();
            for(auto &it: adj[node]){
                if(!vis[it]){
                    q.push({it,level+1});
                }
            }
            len = max(len,level);
        }
        return len+1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n==1){
            res.push_back(0);
            return res;
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        //build the graph, and degrees for each node
        for(auto &it: edges){
            degree[it[0]]++;
            degree[it[1]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q; //populate the queue for topo sort
        for(int i=0; i<n; i++){
            if(degree[i]==1) {
                q.push(i);
            }
        }
        //cout<<q.size()<<endl;
        while(n>2){
            int sz = q.size();
            n -= sz;
            while(sz-- > 0){
                int node = q.front();
                cout<<"node = "<<node<<endl;
                q.pop();
                for(auto &it: adj[node]){
                    degree[it]--;
                    if(degree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }
        while(q.size()){
            int node = q.front();
            res.push_back(node);
            q.pop();
        }
        return res;
    }
};
