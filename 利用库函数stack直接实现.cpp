class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        //不用写，对于自定义类型的，会自动调用其构造函数和析构函数
        
    }
    
    void push(int x) {
        
        s.push(x);
        
        //进行判断寻找当前最小值
        if(min_s.empty() || x <= min_s.top())
        {
            min_s.push(x);
        }
    }
    
    void pop() {
        //先进行判断此时要对最小栈进行判断，把持站定就是当前的最小元素
        if(s.top() == min_s.top())
        {
            min_s.pop();
        }
        s.pop();
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
        
    }
    std::stack<int> s;
    std::stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
