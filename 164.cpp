class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if(nums.size()<2)
			return 0;
		bucketsort(nums);
		int maxgap = 0;
		int i,tmp;
		for(i = 1;i<nums.size();i++)
		{
			tmp = nums[i] - nums[i-1];
			maxgap = maxgap>tmp?maxgap:tmp;
		}
		return maxgap;
	}
	void bucketsort(vector<int>& nums)
	{
		int max = findmax(nums);
		int looptimes = getlooptims(max);
		int i;
		for(i = 1;i<=looptimes;i++)
		{
			_bucketsort(nums,i);
		}
	}
	void _bucketsort(vector<int>& nums,int bitnums)
	{
		vector<int> bits[10];
		int i;
		for(i = 0;i<nums.size();i++)
		{
			bits[getbit(nums[i],bitnums)].push_back(nums[i]);
		}
		nums.clear();
		for(i = 0;i<10;i++)
		{
			nums.insert(nums.end(),bits[i].begin(),bits[i].end());
		}
	}
	int getbit(int num,int bitnums)
	{
		int temp = 0;
		int i;
		for(i = 1;i<=bitnums;i++)
		{
			temp = num%10;
			num = num/10;
		}
		return temp;
	}
	int getlooptims(int& max)
	{
		int count = 1;
		int temp = max/10;
		while(temp)
		{
			count++;
			temp = temp/10;
		}
		return count;
	}
	int findmax(vector<int>& nums)
	{
		int i,max;
		max = nums[0];
		for(i = 1;i<nums.size();i++)
		{
			if(nums[i]>max)
				max = nums[i];
		}
		return max;
	}
};