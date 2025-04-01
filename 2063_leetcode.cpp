class Solution {
private:
    bool isVow(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
public:
    long long countVowels(string word) {
        int n = word.size();
        long long int ans=0;

        for(int i=0; i<n; i++){
            if(isVow(word[i])){
                ans += (i+1)*1LL*(n-i);
            }
        }

        return ans;
    }
};
