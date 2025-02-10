class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        stack<char> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(!(s[i]>='0' && s[i]<='9')){
                st.push(s[i]);
            }
            else{
                if(st.size()){
                    st.pop();
                }
            }
        }
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
