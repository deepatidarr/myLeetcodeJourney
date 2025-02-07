#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &it: kArrays){
        for(auto &i: it){
            pq.push(i);
        }
    }
    vector<int> res;
    while(pq.size()){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
