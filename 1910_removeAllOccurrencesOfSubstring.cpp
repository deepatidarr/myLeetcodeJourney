class Solution {
public:
    void checkTop(stack<char> &st, string &part){
        int m = part.size();
        string tmp = "";
        while(m--){
            tmp += st.top();
            st.pop();
        }
        reverse(tmp.begin(), tmp.end());
        if(part != tmp){
            cout<<tmp<<endl;
            for(auto &ch: tmp){
                st.push(ch);
            }
        }
    }
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = s.size();
        int m = part.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(st.size() >= m){
                checkTop(st, part);
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
