class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        int n = s.size();
        unordered_set<char> st;
        for(int i=0; i<n; i++){
            if(st.find(s[i]) != st.end()){
                ans++;
                st.clear();
            }
            st.insert(s[i]);
        }
        return ans+1;
    }
};
