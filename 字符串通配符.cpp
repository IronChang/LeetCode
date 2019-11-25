#include<iostream>
using namespace std;

bool Match(const char* pattern, const char* str) {
    //两个字符串同时结束返回true，否则返回false
    if (*pattern == '\0' && *str == '\0')
        return true;
    if (*pattern == '\0' || *str == '\0')
        return false;
    
    if (*pattern == '?') {
        // ? 匹配一个字符，直接跳过一个位置
        return Match(pattern + 1, str + 1);
    } else if (*pattern == '*') {
        // * 匹配0个字符，或者匹配一个字符，或者匹配大于一个字符，一个为真即为真
        return Match(pattern+1, str) || Match(pattern+1, str+1) || Match(pattern, str+1);
    } else if (*pattern == *str) {
        // 当前字符相等，匹配下一个字符
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

