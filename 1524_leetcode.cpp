class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long int inf=1e9+7;
        int n = arr.size();
        int ans=0, odd=0, even=1, prefix=0;  
        for(int i=0; i<n; i++){
            prefix += arr[i];
            if(prefix&1){
                ans += even;
                ans = ans%inf;
                odd++;
            }   
            else{
                ans += odd;
                ans = ans%inf;
                even++;
            }
        }
        return ans%inf;
    }
};
