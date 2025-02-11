class Solution {
private:
    int ans = 0;

    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void countPairs(vector<int> &arr, int low, int mid, int high){
    int right = mid+1;

    for(int i=low; i<=mid; i++){
        while(right<=high && arr[i] > 2*1LL*arr[right]){
            right++;
        }
        ans += (right-(mid+1));
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);  // merging sorted halves
}

public:
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        return ans;
    }
};
