class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int result = 1<<31;
		int i,j = 0;
		bool flag = false;
		for(i = 0;i<nums.size();i++)
		{
			if(nums[i] == 0)
			{
				vector<int> tmp(nums.begin() + j,nums.begin() + i);
				int t = func(tmp);
				result = result>t?result:t;
				j = i + 1;
				flag = true;
			}
		}
		vector<int> tmp(nums.begin() + j,nums.begin() + i);
		int t = func(tmp);
		result = result>t?result:t;
		if(flag&&result<0)
		{	
			result = 0;
		}
		return result;
		
	}
	int func(vector<int>& nums)
	{
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		int count = 0;
		for(int i = 0;i < nums.size();i++)
		{
			if(nums[i]<0)
				count++;
		}
		if(count%2 == 0)
		{
			int result = 1;
			for(int i = 0;i < nums.size();i++)
			{
				result*=nums[i];
			}
			return result;
		}
		else
		{
			int result1,result2;
			int tmp = 0;
			result1 = result2 = 1;
			bool flag1,flag2;
			flag1 = true;
			flag2 = false;
			for(int i = 0;i < nums.size();i++)
			{

				if(flag1)
				{
					result1 *= nums[i];
				}
				if(flag2)
				{
					result2 *= nums[i];
				}	
				if(nums[i] < 0)
				{
					tmp++;
					if(tmp == count)
					{
						flag1 = false;
						result1/=nums[i];
					}
					flag2 = true;
				}
			}
			return result1>result2?result1:result2;
		}
	}
};