class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        expand(1,n-1,n,"(");
        return result;
    }
    void expand(int total,int left,int right,string flag)
	{
		if((total==0)&&(left==0)&&(right==0))
			result.push_back(flag);
		if(total<0||right<0||left<0)
			return;
		expand(total+1,left - 1,right,flag+"(");
		expand(total-1,left,right-1,flag+")");
	}
};