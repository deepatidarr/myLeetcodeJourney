class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0.0;
        int prev=0;
        for(auto &it: brackets){
            if(prev > income) break;
            if(income >= it[0]){
                ans += ((it[0]-prev)*(it[1]/100.0));
            }
            else{
                ans += ((income-prev)*(it[1]/100.0));
            }
            prev = it[0];
        }
        return ans;
    }
};
