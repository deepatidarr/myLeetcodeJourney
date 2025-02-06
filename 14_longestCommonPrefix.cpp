class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int n = strs.size();
        string tmp;
        for(int i=1; i<n; i++){
            tmp = "";
            for(int j=0; (j<res.size() && j<strs[i].size()); j++){
                if(res[j] == strs[i][j]){
                    tmp += res[j];
                }
                else{
                    break;
                }
            }
            res = tmp;
        }
        return res;
    }
};
