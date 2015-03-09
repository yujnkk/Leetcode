class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(),num.end());
		vector<vector<int> > result; 
		int i,j,k;
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
				if(s>0)
				{
					k--;
				}
				else if(s<0)
				{
					j++;
				}
				else
				{
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(num[j]);
					tmp.push_back(num[k]);
					result.push_back(tmp);
					j++;
				}
			}
		}
		return result;
	}
};