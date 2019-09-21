class Solution {
public:
    //判断是否是有效字符
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
            //begin从前往后走找到一个有效的字符
            while(begin<end && !IsValidChar(s[begin]))
                begin++;
            
            //end从后往前找到一个有效的字符串
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
