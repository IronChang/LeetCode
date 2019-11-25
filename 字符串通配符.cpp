#include<iostream>
using namespace std;

bool Match(const char* pattern, const char* str) {
    //�����ַ���ͬʱ��������true�����򷵻�false
    if (*pattern == '\0' && *str == '\0')
        return true;
    if (*pattern == '\0' || *str == '\0')
        return false;
    
    if (*pattern == '?') {
        // ? ƥ��һ���ַ���ֱ������һ��λ��
        return Match(pattern + 1, str + 1);
    } else if (*pattern == '*') {
        // * ƥ��0���ַ�������ƥ��һ���ַ�������ƥ�����һ���ַ���һ��Ϊ�漴Ϊ��
        return Match(pattern+1, str) || Match(pattern+1, str+1) || Match(pattern, str+1);
    } else if (*pattern == *str) {
        // ��ǰ�ַ���ȣ�ƥ����һ���ַ�
        return Match(pattern + 1, str + 1);
    }
    return false;
}

int main() {
    string pattern;
    string str;
    while (cin >> pattern >> str) {
        if (Match(pattern.c_str(), str.c_str()))
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    }
    return 0;
}

