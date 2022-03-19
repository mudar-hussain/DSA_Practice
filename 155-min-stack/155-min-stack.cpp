class MinStack {
    private:
    stack<long long> s;
    long long min_ele;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        long long v = val;
        if(s.size() == 0){
            s.push(v);
            min_ele = v;
        }else {
            if(v >= min_ele){
                s.push(v);
            }else{
                long long temp = 2*v*1LL - min_ele;
                s.push(temp);
                min_ele = v;
            }
        }
    }
    
    void pop() {
        if (s.size() == 0) return;
        if(s.top() >= min_ele){
            s.pop();
        }else {
            min_ele = 2* min_ele - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.size() == 0) return -1;
        long long el=s.top();
        if(el<min_ele){
            return min_ele;
        }
        return el;
    }
    
    int getMin() {
        if(s.size()==0) return -1;
        return min_ele;
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