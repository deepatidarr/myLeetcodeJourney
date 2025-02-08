class MedianFinder {
public:
    priority_queue<int> maxheap; // for the first half
    priority_queue<int, vector<int>, greater<int>> minheap; // for the second half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int left = maxheap.size();
        int right = minheap.size();

        if(left == 0){ //this will only happen if its the first number being added
            maxheap.push(num);
        }
        else if(left == right){
            if(num <= minheap.top()){
                maxheap.push(num);
            }
            else{
                int tmp = minheap.top();
                minheap.pop();
                minheap.push(num);
                maxheap.push(tmp);
            }
        }
        else{
            int tmp = maxheap.top();
            if(num > tmp){
                minheap.push(num);
            }
            else{
                maxheap.pop();
                maxheap.push(num);
                minheap.push(tmp);
            }
        }
    }
    
    double findMedian() {
        int left = maxheap.size();
        int right = minheap.size();

        int len = left+right;
        if(len&1) return maxheap.top()*1.0;
        else{
            return (maxheap.top()+minheap.top())/2.0;
        }
    }
};
