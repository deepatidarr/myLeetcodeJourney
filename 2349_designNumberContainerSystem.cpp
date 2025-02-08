class NumberContainers {
public:
    unordered_map<int,int> mp1; //index, value
    unordered_map<int, set<int>> mp2; //value, indices(in a sorted order)
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp1.find(index) == mp1.end()){
            mp1[index] = number;
            mp2[number].insert(index);
        }
        else{
            int tmp = mp1[index];
            mp2[tmp].erase(index);
            if(mp2[tmp].size() == 0){
                mp2.erase(tmp);
            }
            mp1[index] = number;
            mp2[number].insert(index);
        }
    }
    
    int find(int number) {
        if(mp2.find(number) == mp2.end()) return -1;
        auto it = mp2[number].begin();
        return *it;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
