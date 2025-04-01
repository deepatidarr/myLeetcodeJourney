class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> hash(26,0);
        int max_freq=0;
        for(char &c: tasks){
            hash[c-'A']++;
            max_freq = max(max_freq, hash[c-'A']);
        }
        int count_maxes=0;
        for(auto &it: hash){
            if(it == max_freq) count_maxes++;
        }

        int intervals = (max_freq-1)*(n+1) + count_maxes;
        return max(intervals, (int)tasks.size());
    }
};
