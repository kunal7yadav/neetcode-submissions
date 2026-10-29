class MinStack {
public:
stack<long long >st;
long long min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int value) {
        long long x = (long long) value;
        if(st.size()==0){
            st.push(x);
            min = x;
        }
        else if(x>=min) st.push(x);
        else{
            st.push(2*x -min);
            min = x;
        }
    }
    
    void pop() {
        if(st.top()<min){
            long long oldmin = 2*min -st.top();
            min = oldmin;
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<min) return (int)min;
        else return (int)st.top();
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */