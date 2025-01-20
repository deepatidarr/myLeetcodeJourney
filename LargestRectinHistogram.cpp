class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans=0;
        //O(n^2) approach
        // for(int i=0; i<n; i++){
        //     int ht=heights[i];
        //     for(int j=i-1; j>=0; j--){
        //         if(heights[j] < heights[i]) break;
        //         else{
        //             ht += heights[i];
        //         }
        //     }
        //     for(int j=i+1; j<n; j++){
        //         if(heights[j] < heights[i]) break;
        //         else{
        //             ht += heights[i];
        //         }
        //     }
        //     ans = max(ans,ht);
        // }

        //optimised approach
        //what if I store the indexes of previous smaller and next smaller element. That would be the same thing

        // vector<int> pse(n,-1), nse(n,n);
        // stack<pair<int,int>> st; // <num,index>
        // //first calculate pse
        // st.push({heights[0],0}); 
        // for(int i=1; i<n; i++){
        //     if(st.top().first < heights[i]){
        //         pse[i] = st.top().second;
        //     }
        //     else{
        //         while(st.size()){
        //             if(st.top().first >= heights[i]){
        //                 st.pop();
        //             }
        //             else{
        //                 pse[i] = st.top().second;
        //                 break;
        //             }
        //         }
        //     }
        //     st.push({heights[i],i});
        // }
        // while(st.size()) st.pop();
        // st.push({heights[n-1],n-1});
        // for(int i=n-2; i>=0; --i){
        //     if(st.top().first < heights[i]){
        //         nse[i] = st.top().second;
        //     }
        //     else{
        //         while(st.size()){
        //             if(st.top().first >= heights[i]){
        //                 st.pop();
        //             }
        //             else{
        //                 nse[i] = st.top().second;
        //                 break;
        //             }
        //         }
        //     }
        //     st.push({heights[i],i});
        // }
        // for(int i=0; i<n; i++){
        //     int ct=0;
        //     ct = heights[i]*(nse[i]-pse[i]-1);    
        //     ans = max(ct,ans);
        // }

        stack<int> st;
        st.push(0);
        int ct=0;
        int nse=n, pse=-1;
        for(int i=1; i<n; i++){
            int topindex = st.top();
            while(heights[topindex] > heights[i]){
                st.pop();
                if(st.size()==0){
                    pse = -1;
                }
                else{
                    pse = st.top();
                }
                // if(i==n-1) nse = n;
                nse = i;
                ct = heights[topindex]*(nse-pse-1);
                ans = max(ct,ans);
                if(st.size()) topindex = st.top();
                else break;
            }
            st.push(i);
        }
        //for all the elements that remain in the stack, they do not have an nse WHILE the pse is the index before them or -1
        ct=0;
        while(st.size()){
            int tp = st.top(); st.pop();
            if(st.size()) pse = st.top();
            else pse = -1;
            nse = n;
            ct = heights[tp]*(nse-pse-1);
            ans = max(ct,ans);
        }
        return ans;
    }
};
