class Solution {
private:
    bool canMerge(pair<int,int> &tmp, pair<int,int> &p2){
        if(tmp.second >= p2.first) return true;
        return false;
    }
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int,int>> ds;
        for(auto &it: meetings){
            ds.push_back({it[0],it[1]});
        }
        sort(ds.begin(), ds.end());
        vector<pair<int,int>> merged;
        auto tmp = ds[0];
        int n = ds.size();
        for(int i=1; i<n; i++){
            if(canMerge(tmp, ds[i])){
                tmp.first = min(tmp.first, ds[i].first);
                tmp.second = max(tmp.second, ds[i].second);
            }
            else{
                merged.push_back(tmp);
                tmp = ds[i];
            }
        }
        merged.push_back(tmp);
        int ans=0;
        int m = merged.size();
        ans += (merged[0].first-1);
        ans += days-merged[m-1].second;
        for(int i=1; i<m; i++){
            ans += (merged[i].first-merged[i-1].second-1);
        }

        return ans;
    }
};
