class Solution {
private:
    bool isPal(string s, int l, int r){
        while(l<r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void fun(vector<vector<string>>& res, vector<string>& ds, string s, int index){
        if(index == s.size()){
            res.push_back(ds);
        }
        //we check upto i, and we put a partition on this index IF AND ONLY IF the substring upto 'i' is a palindrome
        //we use this function recursively, if it reaches the end, it means we have an occurence of an answer
        for(int i=index; i<s.size(); i++){
            if(isPal(s,index,i)){
                ds.push_back(s.substr(index, i-index+1));
                fun(res, ds, s, i+1);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ds;
        fun(res, ds, s, 0);
        return res;
    }
};
