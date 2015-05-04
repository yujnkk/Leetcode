class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(),nums.end());
		vector<vector<int> > result; 
		int i,w,j,k;
		for(i = 0;i<nums.size();i++)
		{
			if(i>0&&nums[i]==nums[i-1])
				continue;
			for(w=i+1;w<nums.size();w++)
			{
				if(w>(i+1)&&nums[w]==nums[w-1])
					continue;
				j = w+1;
				k = nums.size() - 1;
				while(j < k)
				{
					if(j>w+1&&nums[j]==nums[j-1])
					{
						j++;
						continue;
					}
					if(k<nums.size()-1&&nums[k]==nums[k+1])
					{
						k--;
						continue;
					}
					int s;
					s = nums[i] + nums[w] + nums[j] + nums[k];
					if(s>target)
					{
						k--;
					}
					else if(s<target)
					{
						j++;
					}
					else
					{
						vector<int> tmp;
						tmp.clear();
						tmp.push_back(nums[i]);
						tmp.push_back(nums[w]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[k]);
						result.push_back(tmp);
						j++;
					}
				}
			}
		}
		return result;
	}
};