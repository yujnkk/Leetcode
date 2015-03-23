class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > result;		
		int i;
		vector<int> tmp;
		result.push_back(tmp);
		for(i=1;i<pow(2.0,(double)S.size());i++)
		{
			put(i,S,result);
		}
		sort(result.begin(),result.end());
		vector<vector<int> >::iterator it = unique(result.begin(),result.end());
		result.erase(it, result.end());
		return result;
	}
	void put(uint32_t u,vector<int> &S,vector<vector<int> >&result)
	{
		int n = S.size();
		int i;
		vector<int> tmp;
		for(i=0;i<S.size();i++)
		{
			if(u&1==true)
				tmp.push_back(S[i]);
			u/=2;
		}
		sort(tmp.begin(),tmp.end());
		result.push_back(tmp);
	}
};