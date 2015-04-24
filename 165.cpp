class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> a,b;
		int i,tmp=0;
		for(i=0;i<version1.size();i++)
		{
			if(version1[i]=='.')
			{
				a.push_back(tmp);
				tmp = 0;
				continue;
			}
			tmp = tmp*10 + version1[i] - '0';

		}
		a.push_back(tmp);
		tmp = 0;		
		for(i=0;i<version2.size();i++)
		{
			if(version2[i]=='.')
			{
				b.push_back(tmp);
				tmp = 0;
				continue;
			}
			tmp = tmp*10 + version2[i] - '0';
		}
		b.push_back(tmp);
		for(i=0;i<a.size()&&i<b.size();i++)
		{
			if(a[i]>b[i])
				return 1;
			if(a[i]<b[i])
				return -1;
		}
		if(a.size()==b.size())
			return 0;
		if(a.size()>b.size())
		{
			if(a[i]>0)
				return 1;
			return 0;
		}
		if(b[i]>0)
			return -1;
		return 0;
		

	}
};