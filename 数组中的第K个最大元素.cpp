/*
问题描述：在未排序的数组中找到第 k 个最大的元素。请注意，
你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
思路：利用大小跟堆 

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例?2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/ 

//利用大根堆 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //优先队列底层就是堆，默认建大堆
        //要找最大值就要建最小堆，要找最小值就要建最大堆
        priority_queue<int> p(nums.begin(),nums.end());
        
        for(int i = 0;i<k-1;++i)//删除前k-1最大的数字，那么此时第k位就是此时堆顶 
        {
            p.pop();
        } 
        return p.top();
    }
};


//利用小根堆 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //优先队列底层就是堆，默认建大堆
        //要找最大值就要建最小堆，要找最小值就要建最大堆
        priority_queue<int,vector<int> , greater<int>> data;
        
        for(int i = 0;i<nums.size();i++)
        {
            data.push(nums[i]);
            if(data.size() > k)
            {
                data.pop();
            }
        }
        return data.top();
    }
};
