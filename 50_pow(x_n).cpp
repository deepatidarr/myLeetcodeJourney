class Solution {
public:
    double myPow(double x, int n) {
        long long int nn = n;
        if(n<0) nn *= -1;
        double ans = 1.0;
        while(nn>0){
            if(nn&1){
                ans *= x;
                nn--;
            }
            else{
                x = x*x;
                nn /= 2;
            }
        }
        if(n<0) ans = (double)1.0/ans;
        return ans;
    }
};
