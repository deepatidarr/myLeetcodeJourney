class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> copy;
        int n = nums.size();
        for(int i=0; i<n; i++){
            copy.push_back({nums[i], i});
        } 
        sort(copy.begin(), copy.end());
        int l=0, r=1;
        while(r<n){
            vector<int> tempIndexes;
            tempIndexes.push_back(copy[l].second);
            while(r<n && copy[r].first-copy[r-1].first <= limit){
                tempIndexes.push_back(copy[r].second);
                r++;
            }
            sort(tempIndexes.begin(), tempIndexes.end());
            for(int i=0; i<(r-l); i++){
                nums[tempIndexes[i]] = copy[l+i].first;
            }

            l=r;
            r++;
        }
        return nums;
    }
};
