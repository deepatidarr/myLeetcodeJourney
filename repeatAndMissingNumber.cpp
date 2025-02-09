vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size();
    long long int Sn = (n*(n+1))/2; 
    long long int S2n = (n*(n+1)*(2*n+1))/6;
    
    long long int s=0, s2=0;
    for(int i=0; i<n; i++){
        s += A[i];
        s2 += (long long int)A[i] * (long long int)A[i];
    }
    
    long long int val1 = s-Sn;
    long long int val2 = s2-S2n;
    val2 /= val1;
    long long int x = (val1+val2)/2;
    long long int y = x-val1;
    
    return {(int)x, (int)y};
}
