class MinStack {
    stack<int> s;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min.empty() || min.top()>=val) min.push(val);
        
        else min.push(min.top());
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
            min.pop();
        }
    }
    
    int top() {
        if(!s.empty()) return s.top();
        else return -1;
    }
    
    int getMin() {
        if(!min.empty()) return min.top();
        else return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */