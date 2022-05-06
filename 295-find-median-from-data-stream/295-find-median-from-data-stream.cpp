class MedianFinder {
        priority_queue<int> pqmax;
        priority_queue<int, vector<int>, greater<int>> pqmin;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(pqmax.size() == 0 || pqmax.top()>=num){
            pqmax.push(num);
        }else{
            pqmin.push(num);
        }
        balanceQueue();
    }
    void balanceQueue(){
        int diff = pqmax.size()-pqmin.size();
        if(abs(diff) > 1){
            if(pqmax.size()>pqmin.size()){
                pqmin.push(pqmax.top());
                pqmax.pop();
            }else if(pqmax.size()<pqmin.size()){
                pqmax.push(pqmin.top());
                pqmin.pop();
            }
        }
    }
    
    double findMedian() {
        if(pqmax.size() == pqmin.size())
            return (pqmax.top()+pqmin.top())*1.0/2;
        else if(pqmax.size()>pqmin.size())
            return pqmax.top() * 1.0;
        else 
            return pqmin.top() * 1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */