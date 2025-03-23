class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        int n = recipes.size();

        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indegree;
        unordered_set<string> supply(supplies.begin(), supplies.end());

        for(int i=0; i<n; i++){
            indegree[recipes[i]] = 0;
            for(auto &ingredient: ingredients[i]){
                if(supply.count(ingredient)==0){
                    //means that the ingredient is also a recipe
                    adj[ingredient].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for(auto& it: indegree){
            if(it.second==0){
                q.push(it.first);
            }
        }

        while(q.size()){
            string curr = q.front(); q.pop();
            res.push_back(curr);
            
            for(auto &it: adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        return res;
    }
};
