class Trie{
    struct Node{
        Node *links[2];

        bool containsKey(int bit){
            return (links[bit]!=NULL);
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
            int bit = (num >> i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxor(int num){
        Node* node = root;
        int maxNum = 0;// we are going to create this number from scratch, by placing bits
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){ //(1-bit) because we want to maximise our xor.
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
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int xr = 0;
        Trie tri;
        for(int i=0; i<n; i++){
            tri.insert(nums[i]);
        }
        for(int i=0; i<n; i++){
            ans = max(ans, tri.maxor(nums[i]));
        }
        return ans;
    }
};
