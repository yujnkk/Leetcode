class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(),num.end());
		int i,j,k,close=999999;
		for(i = 0;i<num.size();i++)
		{
			if(i>0&&num[i]==num[i-1])
				continue;
			j = i+1;
			k = num.size() - 1;
			while(j < k)
			{
				if(j>i+1&&num[j]==num[j-1])
				{
					j++;
					continue;
				}
				if(k<num.size()-1&&num[k]==num[k+1])
				{
					k--;
					continue;
				}
				int s;
				s = num[i] + num[j] + num[k];
				if(s>target)
				{
					if(abs(target - s)<abs(target - close))
					{
						close = s;
					}
					k--;
				}
				else if(s<target)
				{
					if(abs(target - s)<abs(target - close))
					{
						close = s;
					}
					j++;
				}
				else
				{
					return target;
				}
			}
		}
		return close;		
	}
};