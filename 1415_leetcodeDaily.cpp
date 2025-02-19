class Solution {
private:
    void genString(vector<string> &res, int n, string &tmp, int index){
        if(tmp.size() == n){
            res.push_back(tmp);
            return;
        }

        for(int i=0; i<3; i++){
            char ch = 'a'+i;
            if(index == 0 || tmp[index-1]!=ch){ 
                tmp += ch;
                genString(res, n, tmp, index+1);
                tmp.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        //the goal is to construct all happy strings of length n
        //ans return kth string assuming the storage is sorted
        vector<string> res;
        string tmp = "";
        genString(res, n, tmp, 0);
        if(k>res.size()) return "";
        return res[k-1];
    }
};
