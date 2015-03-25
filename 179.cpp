class Solution {
public:
	string largestNumber(vector<int> &num) {
		int i,j;
		int t;
		string result;
		string tm;
		for(i=num.size();i>1;i--)
			for(j=0;j<i-1;j++)
			{
				if(small(num[j],num[j+1]))
				{
					t = num[j+1];
					num[j+1] = num[j];
					num[j] = t;					
				}
			}
			if(num[0]==0)
			{
				result.push_back(48);
				return result;
			}
		for(i=0;i<num.size();i++)
		{
			t = num[i];
			tm.clear();
			if(t==0)
				tm.push_back(48);
				while(t)
				{
					tm.push_back(t%10+48);
					t/=10;
				}
			for(j=tm.size()-1;j>=0;j--)
				result.push_back(tm[j]);

		}
		return result;
	}
	bool small(int a,int b)
	{
		if(a==0)
			return true;
		int la=0,lb=0;
		int aa,bb;
		aa = a;
		bb = b;
		while(aa)
		{
			la++;
			aa/=10;
		}
		while(bb)
		{
			lb++;
			bb/=10;
		}
		long long tmp1,tmp2;
		tmp1 = a*pow(10.0,lb)+b;
		tmp2 = b*pow(10.0,la)+a;
		if(tmp1<tmp2)
			return true;
		return false;
	}
};