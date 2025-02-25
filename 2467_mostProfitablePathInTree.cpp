class Solution {
private:
    bool findBobPath(vector<int> &bobPath, vector<vector<int>> &adj, int curr, int parent){
        if(curr==0){
            return true;
        }
        for(auto &it: adj[curr]){
            if(it != parent){
                bobPath.push_back(it);
                if(findBobPath(bobPath, adj, it, curr) == true) return true;
                bobPath.pop_back();
            }
        }
        return false;
    }

    void aliceReward(vector<vector<int>> &adj, vector<int> &amount, int curr, int parent, int &ans, int &maxi){
        ans += amount[curr];
        if(adj[curr].size()==1 && curr!=0){
            maxi = max(maxi,ans);
        }
        for(auto &it: adj[curr]){
            if(it != parent){
                aliceReward(adj, amount, it, curr, ans, maxi);
            }
        }
        ans -= amount[curr];
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> bobPath; bobPath.push_back(bob);
        findBobPath(bobPath, adj, bob, -1);
        int sz = bobPath.size();
        if(sz&1){
            for(int i=0; i<sz/2; i++) amount[bobPath[i]] = 0;
            amount[bobPath[sz/2]] /= 2;
        }
        else{
            for(int i=0; i<sz/2; i++) amount[bobPath[i]] = 0;
        }
        int ans=0, maxi=INT_MIN;
        aliceReward(adj, amount, 0, -1, ans, maxi);
        return maxi;
    }
};
