class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0; i<n; i++){
            int j = 0;
            int x = i;
            while(j<m && x<n){
                if(haystack[x] == needle[j]){
                    x++; j++;
                }
                else{
                    break;
                }
                if(j==m){
                    return x-j;
                }
            }
        }
        return -1;
    }
};
