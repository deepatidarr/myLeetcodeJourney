class Trie{
    struct Node{
        Node* links[2];

        bool containsBit(int bit){
            return (links[bit] != NULL);
        }
        void put(int bit, Node* node){
            links[bit] = node;
        }
        Node* get(int bit){
            return links[bit];
        }
    };
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(!node->containsBit(bit)){
                node->put(bit, new Node());
            }   
            node = node->links[bit];
        }
    }
    int maxor(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsBit(1-bit)){
                maxNum |= (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n,-1);
        vector<pair<int, pair<int,int>>> ds;
        for(int i=0; i<n; i++){
            ds.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(nums.begin(), nums.end());
        sort(ds.begin(), ds.end());
        Trie tri;
        int index = 0;
        for(int i=0; i<ds.size(); i++){
            int limit = ds[i].first;
            int x = ds[i].second.first;
            int j = ds[i].second.second;

            while(index<nums.size() && nums[index] <= limit){
                //cout<<nums[index]<<" ";
                tri.insert(nums[index]);
                index++;
            }
            if(index == 0) res[j] = -1;
            else res[j] = tri.maxor(x);
        }
        return res;
    }
};
