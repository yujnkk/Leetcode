class Solution {  
public:  
	int maxPoints(vector<Point> &points) {  
		// IMPORTANT: Please reset any member data you declared, as  
		// the same Solution instance will be reused for each test case.  
		map<float,int> mp;  
		int maxNum = 0;  
		for(int i = 0; i < points.size(); i++)  
		{  
			mp.clear();  
			mp[INT_MIN] = 0;  
			int duplicate = 1;  
			for(int j = 0; j < points.size(); j++)  
			{  
				if(j == i) continue;  
				if(points[i].x == points[j].x && points[i].y == points[j].y)  
				{  
					duplicate++;  
					continue;  
				}  
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);  
				mp[k]++;  
			}  
			map<float, int>::iterator it = mp.begin();  
			for(; it != mp.end(); it++)  
				if(it->second + duplicate > maxNum)  
					maxNum = it->second + duplicate;  
		}  
		return maxNum;  
	}  
};  