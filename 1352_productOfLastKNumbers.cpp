class ProductOfNumbers {
public:
    vector<int> products;
    int size;
    ProductOfNumbers() {
        size = 0;
    }
    
    void add(int num) {
        if(num == 0){
            products.clear();
        }
        else{
            if(products.size() == 0){
                products.push_back(num);
            }
            else{
                int x = num*products[products.size()-1];
                products.push_back(x);
            }
        }

        // for(auto &it: products){
        //     cout<<it<<" ";
        // }cout<<endl;
    }
    
    int getProduct(int k) {
        int n = products.size();
        if(k > n) return 0;
        int ans = products[n-1];
        if(k==n) return ans;
        ans /= products[n-k-1];
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
