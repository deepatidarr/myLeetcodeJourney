class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> mp;
        int n = s.size();
        vector<string> res;
        for(int i=0; i<n; i++){
            string tmp=""; int a=0;
            for(int j=i; j<n && a<10; j++){
                tmp += s[j]; a++;
            }
            mp[tmp]++;
        }
        for(auto &it: mp){
            if(it.second>1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
