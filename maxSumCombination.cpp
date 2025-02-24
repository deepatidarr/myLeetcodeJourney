/*
Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    int n = A.size();
    priority_queue<pair<int,pair<int,int>>> pq;// {sum, {i,j}}
    set<pair<int,int>> vis; //will store the pair of visited indices {i,j}
    
    pq.push({A[0]+B[0], {0,0}});
    vis.insert({0,0});
    
    vector<int> res;
    
    while(C-- && pq.size()){
        auto top = pq.top(); pq.pop();
        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        res.push_back(sum);
        if(i+1<n && vis.find({i+1,j})==vis.end()){
            pq.push({A[i+1]+B[j], {i+1,j}});
            vis.insert({i+1,j});
        }
        if(j+1<n && vis.find({i,j+1})==vis.end()){
            pq.push({A[i]+B[j+1], {i,j+1}});
            vis.insert({i,j+1});
        }
        
    }
        
    return res;
}
