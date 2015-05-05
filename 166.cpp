class Solution {
public:
	string fractionToDecimal(int  numerato,int denominato) {
		string pre,then;
		long long zs;
		long long numerator,denominator;
		bool flag = false;
        if(numerato==0)
            return "0";
		numerator = numerato;
		denominator = denominato;
		if(numerator<0)
		{
			numerator=-numerator;
			flag = !flag;
		}
		if(denominator<0)
		{
			denominator=-denominator;
			flag = !flag;
		}
		zs = numerator/denominator;
		if(flag)
			pre += '-';
		do 
		{
			pre += zs%10 + '0';
			zs/=10;
		} while(zs);
		if(flag)
			reverse(pre.begin()+1,pre.end());
		else
			reverse(pre.begin(),pre.end());
		map<long long,long long> flags;
		if(numerator==denominator)
			return pre;
		if(numerator>denominator)
		{
			numerator %= denominator;
		}
		long long shang,count = 0;
		flags[numerator] = ++count;
		while (numerator)
		{
			numerator*=10;
			shang = numerator/denominator;
			numerator = numerator%denominator;
			then += (int)shang + '0';
			if(flags[numerator]==0)
			{
				flags[numerator] = ++count;
			}
			else
			{
				string tmp;
				int i;
				for(i=1;i<flags[numerator];i++)
					tmp.push_back(then[i-1]);
				tmp.push_back('(');
				for(;i<count+1;i++)
				{
					tmp.push_back(then[i-1]);
				}
				tmp.push_back(')');
				then.clear();
				then = tmp;
				break;
			}
		}
		if(then.size()!=0)
			return pre+'.'+then;
		return pre;

	}
};