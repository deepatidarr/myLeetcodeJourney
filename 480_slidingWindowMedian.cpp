class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        int n = nums.size();
        multiset<int> ms;
        if(k&1){
            for(int i=0; i<k; i++){
                ms.insert(nums[i]);
            }
            int loc = k/2;
            auto it = ms.begin();
            advance(it, loc);
            res.push_back(*it);
            for(int i=k; i<n; i++){
                auto f = ms.find(nums[i-k]);
                ms.erase(f);
                ms.insert(nums[i]);
                int loc = (k/2);
                auto it = ms.begin();
                advance(it, loc);
                res.push_back(*it);
            }
        }
        else{
            for(int i=0; i<k; i++){
                ms.insert(nums[i]);
            }
            int loc = k/2; int loc2 = (k/2)-1;
            auto it = ms.begin();
            advance(it, loc);
            auto it2 = ms.begin();
            advance(it2, loc2);

            double x = ((*it)/2.0)+((*it2)/2.0);
            res.push_back(x);

            for(int i=k; i<n; i++){
                auto f = ms.find(nums[i-k]);
                ms.erase(f);
                ms.insert(nums[i]);
                int loc = (k/2); int loc2 = (k/2)-1;
                auto it = ms.begin();
                advance(it, loc);
                auto it2 = ms.begin(); advance(it2, loc2);
                double x = ((*it)/2.0)+((*it2)/2.0);
                res.push_back(x);
            }
        }

        return res;
    }
};
