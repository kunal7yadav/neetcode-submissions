class MyStack {
public:
queue<int>q;
queue<int>helper;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if(q.size()==1){
            int x = q.front();
            q.pop();
            return x;
        }
        while(q.size()>1){
            int x = q.front();
            q.pop();
            helper.push(x);
        }
        while(helper.size()>0){
            int x = helper.front();
            helper.pop();
            q.push(x);
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(q.size()==1){
            return q.front();
        }
        while(q.size()>1){
            int x = q.front();
            q.pop();
            helper.push(x);
        }
        while(helper.size()>0){
            int x = helper.front();
            helper.pop();
            q.push(x);
        }
        int x = q.front();
        q.pop();
        q.push(x);
        return x;
    }
    
    bool empty() {
        if(q.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */