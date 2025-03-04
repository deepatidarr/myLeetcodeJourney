class Solution {
private:
    long long powerOf3(int exponent) {
    long long result = 1;  // Use long long to avoid overflow
    for (int i = 0; i < exponent; i++) {
        result *= 3;
    }
    return result;
}
    int tryAll(vector<int> &powers, int index, int target){
        if(target==0) return 1;
        if(index==17){
            if(target==0) return 1;
            return 0;
        }

        int pick = 0;        
        if(powers[index] <= target){
            pick = tryAll(powers, index+1, target-powers[index]);
        }
        int notPick = tryAll(powers, index+1, target);

        return (pick|notPick);
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers(17,0);
        for(int i=0; i<17; i++){
            powers[i] = powerOf3(i);
        }

        return tryAll(powers, 0, n);
    }
};
