class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int>s1;
    stack<int>s2;
    void push(int x) {
        if(s1.empty())
            s1.push(x);
        else{
            while(!s1.empty()){
                int y = s1.top();
                s1.pop();
                s2.push(y);
            }
            s1.push(x);
            while(!s2.empty()){
                int y = s2.top();
                s2.pop();
                s1.push(y);
            }
        }
    }
    
    int pop() {
        int y = s1.top();
        s1.pop();
        return y;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */