void calculateLPS(vector<int> &lps, string &tmp){
    int l=0, r=1;
    while(r<tmp.size()){
        if(tmp[l] == tmp[r]){
            lps[r] = 1+l;
            r++; l++;
        }
        else{
            if(l>0){
                l = lps[l-1];
            }
            else r++;
        }
    }
}

int Solution::solve(string A) {
    int n = A.size();
    string tmp = A;
    reverse(A.begin(), A.end());
    tmp += '*'; tmp += A; reverse(A.begin(), A.end());
    
    int sz = tmp.size(); vector<int> lps(sz,0);
    
    calculateLPS(lps, tmp);
    
    int prefixLen = lps[sz-1];
    return (n-prefixLen);

}
