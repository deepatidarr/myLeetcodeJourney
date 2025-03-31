class Solution {
private:
    bool compare(unordered_map<char,int> &sub, unordered_map<char,int> &target){
        int a=0;
        for(auto &it: target){
            if(sub.find(it.first) != sub.end()){
                if(sub[it.first] >= it.second){
                    a++;
                }
            }
        }
        return a==(target.size());
    }       
public:
    string minWindow(string s, string t) {
        int n = s.size(); int m = t.size();
        unordered_map<char,int> hash;
        for(char &ch: t){
            hash[ch]++;
        }
        //optimised approach
        int l=0, r=0, cnt=0;
        int minLen = INT_MAX, sIndex=-1;
        while(r<n){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++; 
                if(hash[s[l]] > 0){
                    --cnt;
                }
                l++;
                //cout<<l<<" ";
            }
            r++;
        }
        return sIndex==-1 ? "" : s.substr(sIndex,minLen);
        // O(n^2)
        // for(int i=0; i<n; i++){
        //     unordered_map<char,int> sub;
        //     string tmp="";
        //     for(int j=i; j<n; j++){
        //         sub[s[j]]++;
        //         tmp += s[j];
        //         //cout<<tmp<<endl;
        //         if(compare(sub, target)==true){
        //             cout<<"here\n";
        //             if(ans.size()==0){
        //                 ans = tmp;
        //             }
        //             else if(tmp.size()<ans.size())
        //                 ans = tmp;
        //         }
        //     }
        // }
        // return ans;
    }
};
