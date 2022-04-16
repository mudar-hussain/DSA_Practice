class StockSpanner {
    stack<pair<int, int>> span;
public:
    StockSpanner() {
        while(!span.empty()) span.pop();
    }
    
    int next(int price) {
        
        int count = 1;
        while(!span.empty() && price>=span.top().first){
            count += span.top().second;
            span.pop();
        }
        span.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */