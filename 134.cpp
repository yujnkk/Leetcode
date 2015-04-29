class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int gsum,csum;
		gsum=csum=0;
		int i;
		for(i=0;i<gas.size();i++)
		{
			gsum+=gas[i];
			csum+=cost[i];
			gas[i]-=cost[i];
		}
		if(csum>gsum)
			return -1;
		int tmp,result;
		i=0;
		while(i<gas.size())
		{
			for(;i<gas.size();i++)
			{
				if(gas[i]<0)
					continue;
				else
					break;
			}
			result = i;
			tmp = gas[i];
			i++;
			for(;i<gas.size();i++)
			{
				if(tmp<0)
					break;
				tmp+=gas[i];
			}
		}
		return result;
	}
};