class Solution {
public:
    int firstUniqChar(string s) {
        
        //ԭ������ ��������
        //ͳ��ÿһ���ַ����ֵĴ���
        int count[256]= {0};
        int size = s.size();
        
        for(int i = 0; i < size; ++i)
        {
            count[s[i]] +=1;
        }
        
        //�����ַ����ִ�ǰ������ֻ����һ�ε��ַ�
        for(int i = 0; i<size; ++i)
        {
            if( 1 == count[s[i]])
            {
                return i;
            }
        }
        return -1;
    }
};
