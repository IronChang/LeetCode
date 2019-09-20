class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        //��֤num1�ǽϳ�����һ���ַ���
        int Lsize = num1.size();
        int Rsize = num2.size();
        
        if(Lsize < Rsize)
        {
            num1.swap(num2);//����num1��num2�е�����
            swap(Lsize,Rsize);//��������
        }
        
        //����Ӻ�Ľ��
        string strRet;
        strRet.reserve(Lsize+1);
        
        //��������ȥÿһλ��������,����н�λ������Ͻ�λ
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
