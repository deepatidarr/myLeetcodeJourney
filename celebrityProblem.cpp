class Solution {
  public:
    bool knows(int i, int j, vector<vector<int> > &mat){
        return mat[i][j];
    }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> > &mat) {
        // code here
        if(mat.size() == 1) return 0;
        int n = mat.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        while(st.size()>1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(knows(a,b,mat)) st.push(b);
            else st.push(a);
        }
        
        int c = st.top();
        st.pop();
        
        for(int i=0; i<n; i++){
            if(i!=c && (knows(c,i,mat) || !knows(i,c,mat))) return -1;
        }
        return c;
    }
