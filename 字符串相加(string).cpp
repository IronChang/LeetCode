class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        //保证num1是较长的哪一个字符串
        int Lsize = num1.size();
        int Rsize = num2.size();
        
        if(Lsize < Rsize)
        {
            num1.swap(num2);//交换num1和num2中的内容
            swap(Lsize,Rsize);//交换长度
        }
        
        //保存加厚的结果
        string strRet;
        strRet.reserve(Lsize+1);
        
        //从右往左去每一位进行运算,如果有进位，则加上进位
        char step = 0;
        char cret = 0;
        for(int i = 0; i<Lsize;++i)
        {
            cret = num1[Lsize - i - 1] - '0' + step;
            step = 0;
            
            if(i < Rsize)
            {
               cret += num2[Rsize - i - 1] - '0'; 
            }


            if(cret >= 10)
            {
                step = 1;
                cret-=10;
            }
            
            strRet+=cret+'0';
            
        }
        
        if(step)
        strRet += '1';
        reverse(strRet.begin(), strRet.end()); 
        return strRet;     
    }
};
