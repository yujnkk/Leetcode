class Solution {
public:
	int ladderLength(string start, string end, set<string> &dict) {
		queue<string> fromStart, fromEnd;
		set<string> frontierStart, frontierEnd;
		fromStart.push(start);
		fromEnd.push(end);
		frontierStart.insert(start);
		frontierEnd.insert(end);
		int dist=1;

		while(!fromStart.empty()&&!fromEnd.empty()){
			if(fromStart.size()<=fromEnd.size()){
				if(stepForward(fromStart, dict, frontierStart, frontierEnd)) 
					return dist + 1;
			}else{
				if(stepForward(fromEnd, dict, frontierEnd, frontierStart)) 
					return dist + 1;
			}
			dist++;
		}
		return 0;
	}
	bool stepForward(queue<string> &levelQ, set<string> &dict,
			set<string> &frontSelf, set<string> &frontOther){
			queue<string> nextLevelQ;
			vector<string> another(dict.begin(),dict.end());
			vector<string> another1(frontOther.begin(),frontOther.end());
			frontSelf.clear();
			while(!levelQ.empty()){
				string currWord = levelQ.front();
				levelQ.pop();
				for(int i=0;i<another.size();i++){																
						if(diffrencewithwords(another[i],currWord) == 1){
							dict.erase(another[i]);
							nextLevelQ.push(another[i]);
							frontSelf.insert(another[i]);
						}					           
				}
				for(int i=0;i<another1.size();i++)
				{
					if(diffrencewithwords(another1[i],currWord) == 1)
						return true;
				}
			}
			levelQ.swap(nextLevelQ);
			return false;
	}
	int diffrencewithwords(const string &a,const string&b)
	{
		int result = 0;
		for(int i=0;i<a.size();i++)
		{			
			if(a[i]!=b[i])
				result++;
		}
		return result;
	}
};