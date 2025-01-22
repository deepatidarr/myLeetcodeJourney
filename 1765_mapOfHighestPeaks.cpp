class Solution {
    vector<pair<int,int>> moves = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool isValid(int n, int m, int i, int j, vector<vector<int>>& vis){
        if(i<n && j<m && i>=0 && j>=0 && vis[i][j]==0) return true;
        return false;
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j] == 1) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
                isWater[i][j] = !isWater[i][j];
            }
        }
        while(q.size()){
            auto ii = q.front().first;
            auto jj = q.front().second;
            q.pop();
            for(auto &mov: moves){
                if(isValid(n, m, ii+mov.first, jj+mov.second, vis)){
                    isWater[ii+mov.first][jj+mov.second] = isWater[ii][jj]+1;
                    vis[ii+mov.first][jj+mov.second] = 1;
                    q.push({ii+mov.first, jj+mov.second});
                }
            }

        }
        return isWater;
    }
};
