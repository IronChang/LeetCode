#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        return 1<<(number-1);
    }
};

int main()
{
	int n = 0;
	Solution s;
	while(cin>>n)
	{
		cout<<s.jumpFloorII(n)<<endl;
	}
	return 0;
 } 
