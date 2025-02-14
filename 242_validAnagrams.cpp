class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(); int m = t.size();
        if(n!=m) return false;
        vector<int> h1(26,0), h2(26,0);
        for(int i=0; i<n; i++){
            h1[s[i]-'a']++;
            h2[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(h1[i] != h2[i]) return false;
        }
        return true;
    }
};
