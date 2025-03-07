class Solution {
private:
    bool isPrime(int x){
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res;// = {-1,-1};
        stack<int> prime;
        int diff = INT_MAX;
        for(int i=left; i<=right; i++){
            if(isPrime(i)){
                if(prime.size()){
                    if(diff > i-prime.top()){
                        diff = i-prime.top();
                        res = {prime.top(), i};
                        //prime.pop();
                    }
                }
                prime.push(i);
            }
        }
        if(diff == INT_MAX) return {-1,-1};
        return res;
    }
};
