//CLASSIC BINARY SEARCH PROBLEM.
//USE BINARY SEARCH IN THE PROBLEM SPACE.

bool isPossible(int limit, int students, vector<int>& A){
    int stu=1;
    int n = A.size();
    int pages=0;
    for(int i=0; i<A.size(); i++){
        if(A[i] > limit) return false;
        if(pages + A[i] <= limit){
            pages+=A[i];
        }
        else{
            stu++;
            pages = A[i];
        }
    }
    if(stu > students) return false;
    return true;
}

int Solution::books(vector<int> &A, int b) {
    int n = A.size();
    if(b>n) return -1;
    int lo = INT_MAX;
    for(int i=0; i<n; i++) lo = min(lo, A[i]);
    int hi = 0;
    for(int i=0; i<n; i++) hi += A[i];
    int ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        if(isPossible(mid, b, A)){
            hi = mid-1;
            ans = mid;
        }
        else{
            lo = mid+1;
        }
    }
    return ans;
}
