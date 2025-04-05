class Solution {
private:
    long long fun(vector<vector<int>>& questions, int i, vector<long long> &dp){
        if(i>=questions.size()){
            return 0;
        }
        if(i==questions.size()-1){
            return questions[i][0];
        }
        if(dp[i] != -1) return dp[i];

        long long pick = 1LL*questions[i][0] + fun(questions, i+questions[i][1]+1, dp);
        long long notPick = fun(questions, i+1, dp);

        return dp[i] = max(pick,notPick);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return fun(questions, 0, dp);
    }
};
