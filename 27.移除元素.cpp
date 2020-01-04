class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		//sort(nums.begin(), nums.end());
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[j++] = nums[i];
			}
		}
		return j;
	}
};

int main()
{
	int myints[] = { 30, 20, 20, 20, 30, 30 };
	vector<int> nums(myints, myints+5);
	Solution s;
	s.removeElement(nums,30);
	system("pause");
	return 0;
}
