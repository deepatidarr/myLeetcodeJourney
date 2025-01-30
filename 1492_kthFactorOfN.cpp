class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i=1; i<=n/2; i++){
            if(n%i == 0){
                factors.push_back(i);
            }
        }
        factors.push_back(n);
        for(auto& i: factors){
            cout << i << " ";
        }
        if(factors.size() < k) return -1;
        return factors[k-1];
    }
};
