class MinStack {
    
    Stack<Integer> st = new Stack<>();
    Stack<Integer> minSt = new Stack<>();

    public MinStack() {
        
    }
    
    public void push(int value) {
        
        if(minSt.isEmpty() || minSt.peek() >= value)
            minSt.push(value);
        
        st.push(value);
    }
    
    public void pop() {
        
        if(st.peek().equals(minSt.peek()))
            minSt.pop();
        st.pop();
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minSt.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */