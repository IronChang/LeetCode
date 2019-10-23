class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size())
        {
            return false;
        }
        
        int outidx = 0;
        int inidx = 0;
        stack<int> s;
        
        while(inidx < popV.size())
        {
            s.push(pushV[inidx++]);
            
            while(!s.empty() && s.top() == popV[outidx])
            {
                    s.pop();
                    ++outidx;
            }
        }
        
     return s.empty();
    }
};
