class MedianFinder {
public:
    vector <int> arr;
    priority_queue <int> maxheap;
    priority_queue <int, vector<int> , greater<int>> minheap;
    double median;
    
    int signum(int a,int b){
        if(a==b) return 0;
        if(a>b) return 1;
        else return -1;
    }
    
    MedianFinder() {
        median=-1;
    }



    
    void addNum(int num) {
        switch(signum(maxheap.size(),minheap.size())){
            case 0:
                if(num>median){
                    minheap.push(num);
                    median=minheap.top();
                }
                else{
                    maxheap.push(num);
                    median=maxheap.top();
                }
                break;

            case 1:
                if(num>median){
                    minheap.push(num);
                    median=(double)(minheap.top()+maxheap.top())/2.0;
                }
                else{
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                    median=(double)(minheap.top()+maxheap.top())/2.0;
                }
                break;
            
            case -1:
                if(num<median){
                    maxheap.push(num);
                    median=(double)(minheap.top()+maxheap.top())/2.0;
                }
                else{
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                    median=(double)(minheap.top()+maxheap.top())/2.0;
                }
                break;
        }
        
    }
    
    double findMedian() {
        return median;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */