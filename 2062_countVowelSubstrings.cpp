class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int n = word.size();
        int ans=0;
        for(int i=0; i<n; i++){
            unordered_set<char> check;
            for(int j=i; j<n; j++){
                if(vowels.find(word[j]) != vowels.end()){
                    check.insert(word[j]);
                    if(check.size() == 5) ans++;
                }
                else break;
            }
        }
        return ans;
    }
};
