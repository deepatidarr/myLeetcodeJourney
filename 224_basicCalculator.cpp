class Solution {
private:
    bool isDigit(char ch){
        if(ch>='0' && ch<='9') return true;
        return false;
    }
public:
    int calculate(string s) {
        int n = s.size();
        int sign = 1;
        int ans = 0;
        stack<int> st;
        string cur="";

        for(int i=0; i<n; i++){
            if(s[i]==' ') continue;
            else if(isDigit(s[i])){
                while(isDigit(s[i])){
                    cur += s[i];
                    i++;
                }
                ans += stoi(cur)*sign;
                --i;
            }
            else if(s[i]=='+'){
                cur = "";
                sign = 1;
            }
            else if(s[i]=='-'){
                cur = "";
                sign = -1;
            }
            else{
                if(s[i]=='('){
                    st.push(ans);
                    st.push(sign);
                    ans = 0;
                    sign = 1;
                }
                else if(s[i]==')'){
                    ans = ans*st.top(); st.pop();
                    ans += st.top(); st.pop();
                }
            }
        }
        return ans;
    }
};
