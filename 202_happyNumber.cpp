class Solution {
private:
    int sumOf(int n){
        int sum=0;
        while(n){
            int digit = n%10;
            sum += (digit*digit);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int sum = sumOf(n);
        unordered_set<int> s;
        if(sum == 1) return true;
        while(true){
            sum = sumOf(sum);
            if(sum == 1) return true;
            if(s.find(sum) != s.end()) return false;
            s.insert(sum);
        }
        return false;
    }
};
