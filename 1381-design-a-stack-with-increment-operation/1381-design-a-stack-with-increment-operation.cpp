class CustomStack {
public:
    CustomStack(int maxSize) {
        top = -1;
        capacity = maxSize;
        stk.resize(capacity);
        diff.resize(capacity);
    }
    
    void push(int x) {
        if (top == capacity - 1) return;
        stk[++top] = x;
    }
    
    int pop() {
        if (top == -1) return -1;
        
        int val = stk[top] + diff[top];
        if (top > 0) diff[top - 1] += diff[top];
        diff[top] = 0;
        stk[top] = 0;
        --top;
        
        
        return val;
    }
    
    void increment(int k, int val) {
        int max_reach = min(k - 1, top);
        if (max_reach >= 0) diff[max_reach] += val;
    }
    
private:
    int capacity, top;
    vector<int> stk, diff;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */