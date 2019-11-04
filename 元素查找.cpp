/*
问题描述：
给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，
请返回x的位置(位置从零开始)。保证数组中元素互异。
方法：二分查找 
*/
class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here
        int left = 0;
        int right = n-1;
        while(left<=right)
        {
            int mid = (left + right)/2;
            
            if(A[mid] == x)
                return mid;
            
            //[left,mid] [mid,right]
            if(A[left] < A[mid])
            {
                if(A[left] <= x && x<A[mid])
                {
                    right = mid -1;
                }
                else
                {
                    left = mid +1;
                }
            }
            else
            {
                if(A[mid] < x && x<=A[right])
                {
                    left = mid +1;
                }
                else
                {
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};
