/*
������������δ������������ҵ��� k ������Ԫ�ء���ע�⣬
����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء� 
˼·�����ô�С���� 

��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

ʾ�� 1:

����: [3,2,1,5,6,4] �� k = 2
���: 5
ʾ��?2:

����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4
*/ 

//���ô���� 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //���ȶ��еײ���Ƕѣ�Ĭ�Ͻ����
        //Ҫ�����ֵ��Ҫ����С�ѣ�Ҫ����Сֵ��Ҫ������
        priority_queue<int> p(nums.begin(),nums.end());
        
        for(int i = 0;i<k-1;++i)//ɾ��ǰk-1�������֣���ô��ʱ��kλ���Ǵ�ʱ�Ѷ� 
        {
            p.pop();
        } 
        return p.top();
    }
};


//����С���� 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //���ȶ��еײ���Ƕѣ�Ĭ�Ͻ����
        //Ҫ�����ֵ��Ҫ����С�ѣ�Ҫ����Сֵ��Ҫ������
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
