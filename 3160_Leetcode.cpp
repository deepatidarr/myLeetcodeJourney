class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n = q.size();
        vector<int> res;
        unordered_map<int,int> balls, colors;
        for(int i=0; i<n; i++){
            int b = q[i][0];
            int c = q[i][1];

            if(balls.find(b) != balls.end()){
                int tc = balls[b];
                colors[tc]--;
                if(colors[tc] == 0) colors.erase(tc);
            }

            balls[b] = c;
            colors[c]++;

            res.push_back(colors.size());
        }
        return res;
    }
};
