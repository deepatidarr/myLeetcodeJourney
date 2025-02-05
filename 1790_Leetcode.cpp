class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        vector<int> h1(26, 0), h2(26, 0);
        int n = s1.size();
        int ct=0;
        for(int i=0; i<n; i++){
            h1[s1[i]-'a']++;
            h2[s2[i]-'a']++;
            if(s1[i] != s2[i]){
                ct++;
            }
        }        
        for(int i=0; i<26; i++){
            if(h1[i]!=h2[i]) return false;
        }
        if(ct>2) return false;
        return true;
    }
};
