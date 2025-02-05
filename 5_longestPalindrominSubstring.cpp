class Solution {
public:
    int isPal(string tmp){
        int right = tmp.size()-1; int left = 0;
        while(left <= right){
            if(tmp[left++] != tmp[right--]) return 0;
        }
        return tmp.size();
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans=""; int sz=0;
        for(int i=0; i<n; i++){
        string tmp = "";
            for(int j=i; j<n; j++){
                tmp += s[j];
                //cout<<tmp<<endl;
                if(isPal(tmp) > sz){
                    //cout<<"here"<<endl;
                    ans = tmp;
                    sz = tmp.size();
                }
            }
        }
        return ans;
    }
};
