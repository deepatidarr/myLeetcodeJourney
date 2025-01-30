class Solution {
private:
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0; i<4; i++){
            if(check(mat, target)) return true;
            rotate(mat);
        }
        return false;
    }
};
