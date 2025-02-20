class Solution {
private:
    void genString(int n, unordered_set<string> &st, string &tmp){
        if(tmp.size()==n){
            st.insert(tmp); return;
        }
        for(int i=0; i<2; i++){
            tmp += to_string(i);
            genString(n, st, tmp);
            tmp.pop_back();
        }


    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> st;
        int n = nums.size();
        string tmp = "";
        genString(n, st, tmp);
        for(auto &it: nums){
            st.erase(it);
        }
        if(st.size()){
            auto str = st.begin();
            return *str;
        }
        return "";
    }
};
