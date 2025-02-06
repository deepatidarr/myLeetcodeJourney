class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size();
        for(int i=0; i<n; i++){
            //for every index we wanna check for an odd length palindrom, ans an even length pal
            int mid = i;
            int l=mid-1, r=mid+1;
            while(l>=0 && r<n){
                if(s[l] == s[r]) {
                    l--; r++;
                }
                else break;
            } l++; r--;
            string s1 = s.substr(l, r-l+1);
            string s2;
            //now lets say the string is an even length palindrome
            if(i<n-1 && s[i]==s[i+1]){
                int mid1 = i, mid2=i+1;
                l = mid1-1, r=mid2+1;
                while(l>=0 && r<n){
                    if(s[l] == s[r]){
                        l--; r++;
                    }
                    else break;
                } l++; r--;
                s2 = s.substr(l, r-l+1);
            }
            if(s1.size() > ans.size()){
                ans = s1;
            }
            if(s2.size() > ans.size()){
                ans = s2;
            }
        }
        return ans;
    }
};
