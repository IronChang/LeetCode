#include<iostream>
#include<map> 
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10},  {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res=0;
        int len=s.size();
        for(int i=0;i<len-1;++i)
        {   
            if(m[s[i]]<m[s[i+1]])
                res-=m[s[i]];
            else res+=m[s[i]];
        }
        res+=m[s[len-1]];
        return res;
    }
};

int main()
{
	Solution s;
	cout<<s.romanToInt("IIII")<<endl;
	return 0;
 } 


