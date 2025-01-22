//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> res(V, 1e8);
        res[src] = 0;
        for(int i=0; i<V-1; i++){
            for(auto &it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(res[u] != 1e8 && res[u]+wt < res[v]){
                    res[v] = res[u] + wt;
                }
            }
        }
        
        //Nth iteration to check for negative cycles
        for(auto &it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(res[u] != 1e8 && res[u]+wt < res[v]){
                    return {-1};
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
