class Solution {
private:
    bool fun(string s, string p){
        if(p.size() == 0){
            return s.size() == 0;
        }

        bool firstCharMatch = false;
        if(s.size()>0 && (s[0] == p[0] || p[0]=='.')){
            firstCharMatch = true;
        }

        if(p[1]=='*'){
            bool take = firstCharMatch && fun(s.substr(1), p); // this means we will consider the * in the next call
            bool notTake = fun(s, p.substr(2));

            return take|notTake;
        }
        
        return firstCharMatch && fun(s.substr(1), p.substr(1));   
    }
public:
    bool isMatch(string s, string p) {
        return fun(s, p);
    }
};
