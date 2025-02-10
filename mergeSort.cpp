void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> tmp;

    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            tmp.push_back(arr[left]); left++;
        }
        else{
            tmp.push_back(arr[right]); right++;
        }
    }
    while(left <= mid) tmp.push_back(arr[left++]);
    while(right <= high) tmp.push_back(arr[right++]);

    for(int i=low; i<=high; i++){
        arr[i] = tmp[i-low];
    }
}

void mS(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low+high)>>1;

    mS(arr, low, mid);
    mS(arr, mid+1, high);

    merge(arr, low, mid, high);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mS(arr, 0, n-1);
}
