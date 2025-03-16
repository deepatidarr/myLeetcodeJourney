class Solution {
private:
    bool isPossible(vector<int> &ranks, int &cars, long long &mid){
        //we have to fins if its possible to repair 'cars' in mid minutes
        long long totalCars=0;
        for(int i=0; i<ranks.size(); i++){
            //how many cars can rank[i] repair in mid minutes?
            totalCars += sqrt(mid/(ranks[i]));
        }
        return totalCars>=cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long ans=0;
        int n = ranks.size();
        long long lo = *min_element(ranks.begin(), ranks.end());
        long long hi = lo*1LL*cars*1LL*cars;
        while(lo <= hi){
            long long  mid = (lo+hi)>>1;
            if(isPossible(ranks, cars, mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
