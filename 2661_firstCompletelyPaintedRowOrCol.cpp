class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int a = arr.size();
        unordered_map<int,int> rows, cols;
        unordered_map<int,pair<int,int>> coords;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                coords[mat[i][j]] = {i,j};
            }
        }

        for(int i=0; i<a; i++){
            int r = coords[arr[i]].first;
            int c = coords[arr[i]].second;
            rows[r]++;
            if(rows[r]==m) return i;
            cols[c]++;
            if(cols[c] == n) return i;
        }
        return a;
    }
};
