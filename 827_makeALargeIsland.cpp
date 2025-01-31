class Solution {
private:
    void findArea(vector<vector<int>>& grid, int i, int j, int n, int& area){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j] != 1) return;
        area++;
        grid[i][j] = -1;

        findArea(grid, i+1, j, n, area);
        findArea(grid, i-1, j, n, area);
        findArea(grid, i, j+1, n, area);
        findArea(grid, i, j-1, n, area);
    }
    void populate(vector<vector<int>>& grid, int i, int j, int n, int area, vector<vector<pair<int,int>>>& copy, int id){
        if(i<0 || j<0 || i>=n || j>=n || grid[i][j] != -1) return;

        grid[i][j] = area;
        copy[i][j].first = area;
        copy[i][j].second = id;

        populate(grid, i+1, j, n, area, copy, id);
        populate(grid, i-1, j, n, area, copy, id);
        populate(grid, i, j+1, n, area, copy, id);
        populate(grid, i, j-1, n, area, copy, id);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<pair<int, int>>> copy(n, vector<pair<int, int>>(n, {0, 0}));
        int id = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    findArea(grid, i, j, n, area);
                    ans = max(ans, area);
                    populate(grid, i, j, n, area, copy, id);
                    ++id;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(copy[i][j].first == 0){
                    unordered_set<int> ids;
                    int tmp = 1;
                    if((i+1 < n) && ids.find(copy[i+1][j].second) == ids.end()) {
                        tmp += copy[i+1][j].first; ids.insert(copy[i+1][j].second);
                    }
                    if((i-1 >= 0) && ids.find(copy[i-1][j].second) == ids.end()) {
                        tmp += copy[i-1][j].first; ids.insert(copy[i-1][j].second);
                    }
                    if((j+1 < n) && ids.find(copy[i][j+1].second) == ids.end()) {
                        tmp += copy[i][j+1].first; ids.insert(copy[i][j+1].second);
                    }
                    if((j-1 >= 0) && ids.find(copy[i][j-1].second) == ids.end()) {
                        tmp += copy[i][j-1].first; ids.insert(copy[i][j-1].second);
                    }
                    ans = max(ans, tmp);
                }
            }
        }

        return ans;
    }
};
