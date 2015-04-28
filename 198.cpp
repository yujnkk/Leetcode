class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size()==0)
			return 0;
		if(nums.size()==1)
			return nums[0];
		vector<int> result;
		result.push_back(nums[0]);
		result.push_back(nums[1]>nums[0]?nums[1]:nums[0]);
		int i;
		for(i = 2;i<nums.size();i++)
		{
			result.push_back((result[i-2]+nums[i])>result[i-1]?(result[i-2]+nums[i]):result[i-1]);
		}
		return result[i-1]>result[i-2]?result[i-1]:result[i-2];
	}
};