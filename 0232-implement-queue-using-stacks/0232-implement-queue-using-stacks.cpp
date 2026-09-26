class MyQueue {
public:
 stack<int>s1;
 stack<int>s2;
 //maintain s2 as queue
    MyQueue() {
         

    }
    
    void push(int x) {
        s1.push(x);

    }
    
    int pop() {
        if(!s2.empty()) {
          int p=s2.top();
          s2.pop();
          return p;
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            int p=s2.top();
            s2.pop();

          return p;
        }
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }

            return s2.top();
        }
        
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
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