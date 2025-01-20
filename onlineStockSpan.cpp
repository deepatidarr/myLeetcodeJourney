class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i=-1;
    StockSpanner() {
        st.push({INT_MAX,i});
        i++;
    }
    
    int next(int price) {
        while(st.size() && st.top().first <= price){
            st.pop();
        }
        int ans = i-st.top().second;
        st.push({price,i});
        ++i;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
