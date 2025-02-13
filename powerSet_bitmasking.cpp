//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> res;
		    int n = s.size();
		    
		    for(int i=0; i < (1<<n); i++){
		        string tmp = "";
		        for(int j=0; j<n; j++){
		            if(i & (1<<j)){
		                tmp += s[j];
		            }
		        }
		        if(tmp.size() > 0){
		            res.push_back(tmp);
		        }
		    }
            sort(res.begin(), res.end());
		    return res;

		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
