class Solution {
private:
    int solve(vector<int>& days, vector<int>& costs, int index, int reach, unordered_map<int,int> &dp){
        if(index>=days.size()) return 0;
        if(reach >= days[index]){
            return solve(days, costs, index+1, reach, dp); //no additional ticket to be purchased
        }

        if(dp[index]) return dp[index]; 

        int one = costs[0]+solve(days, costs, index+1, days[index], dp);
        int week = costs[1]+solve(days, costs, index+1, days[index]+6, dp);
        int month = costs[2]+solve(days, costs, index+1, days[index]+29, dp);

        return dp[index] = min({one,week,month});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> dp;
        return min({costs[0]+solve(days, costs, 0, days[0], dp),
                costs[1]+solve(days, costs, 0, days[0]+6, dp),
                costs[2]+solve(days, costs, 0, days[0]+29, dp)});
    }
};
