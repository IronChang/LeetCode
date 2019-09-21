class Solution {
public:
    //�ж��Ƿ�����Ч�ַ�
    bool IsValidChar(char ch)
    {
        if((ch >= '0' && ch <= '9') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }
        
        return false;
    }
    
    
    bool isPalindrome(string s) 
    {
        
        if(s.empty())
            return true;
        
        int begin = 0;
        int end = s.size()-1;
        
        while(begin<end)
        {
            //begin��ǰ�������ҵ�һ����Ч���ַ�
            while(begin<end && !IsValidChar(s[begin]))
                begin++;
            
            //end�Ӻ���ǰ�ҵ�һ����Ч���ַ���
            while(begin<end && !IsValidChar(s[end]))
                end--;
            
            if(begin <  end) 
            {
               if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
                return false;
            }
            
            ++begin;
            --end;
        }     
        
        return true;
    }
};
