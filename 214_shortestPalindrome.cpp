class Solution {
private:
    void calculateLPS(string &tmp, vector<int> &lps){
        int l=0, r=1;
        int n = tmp.size();
        while(r<n){
            if(tmp[l] == tmp[r]){
                lps[r] = 1+l;
                r++; l++;
            }
            else{
                if(l>0){
                    l = lps[l-1];
                }
                else{
                    r++;
                }
            }
        }
    }
public:
    string shortestPalindrome(string s) {
        string res="";
        int n = s.size();
        string tmp = s;
        tmp += '*';
        reverse(s.begin(), s.end()); tmp += s;
        int sz = tmp.size();
        vector<int> lps(sz,0);
        reverse(s.begin(), s.end());
        calculateLPS(tmp, lps);
        int prefixSize = lps[sz-1];
        
        string x = s.substr(prefixSize);
        reverse(x.begin(), x.end());
        //cout<<x<<endl;

        res = x+s;
        return res;
    }
};
