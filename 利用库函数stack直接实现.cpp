class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        //����д�������Զ������͵ģ����Զ������乹�캯������������
        
    }
    
    void push(int x) {
        
        s.push(x);
        
        //�����ж�Ѱ�ҵ�ǰ��Сֵ
        if(min_s.empty() || x <= min_s.top())
        {
            min_s.push(x);
        }
    }
    
    void pop() {
        //�Ƚ����жϴ�ʱҪ����Сջ�����жϣ��ѳ�վ�����ǵ�ǰ����СԪ��
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
