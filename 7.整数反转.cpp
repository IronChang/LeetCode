class Solution {
public:
    int reverse(int x) {
    	int flag = x > 0 ? 1 : -1;
    	long int y = (long int)x;
    	y = y * flag;
    	int tmp = 0;
		long int result = 0;
    	while(y > 0) {
    		tmp = y % 10;
    		result = result * 10 +tmp;
    		if(flag * result > INT_MAX || flag * result < INT_MIN)
    			return 0;
    		y = y / 10;
		}
		return flag * result;
    }
}; 


