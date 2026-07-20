class MinStack {
public:
    stack<int> stk;
    deque<int> dq;
    
    MinStack() {
        dq.push_back(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        if(val <= dq.front()) dq.push_front(val);
    }
    
    void pop() {
        if(stk.top() == dq.front()) dq.pop_front();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return dq.front();
    }
};