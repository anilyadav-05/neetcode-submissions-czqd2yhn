class MyQueue {
    stack<int>s;
    stack<int>k;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
       while(s.size() != 1){
        k.push(s.top());
        s.pop();
       }
       int x = s.top();
       s.pop();
       
       while(0 != k.size()){
        s.push(k.top());
        k.pop();
       }
       return x;
    }
    
    int peek() {
        while(s.size() != 1){
        k.push(s.top());
        s.pop();
       }
       int x = s.top();
       
       while(0 != k.size()){
        s.push(k.top());
        k.pop();
       }
       return x;
    
    }
    
    bool empty() {
        return s.empty();
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