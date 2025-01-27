class Solution {
private:
    int large = 1e3;
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qs) {
        //to solve this problem optimally, we will use the Floyd Warshall algorithm
        vector<vector<int>> floyd(n, vector<int> (n,large));
        int m=pre.size();
        for(int i=0; i<m; i++){
            floyd[pre[i][0]][pre[i][1]] = 1;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    floyd[i][j] = min(floyd[i][j], (floyd[i][k]+floyd[k][j]));
                }
            }
        }
        vector<bool> res;
        for(int i=0; i<qs.size(); i++){
            if(floyd[qs[i][0]][qs[i][1]] != large) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
