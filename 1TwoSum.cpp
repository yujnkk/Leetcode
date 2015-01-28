class Solution {
 public:
	 vector<int> twoSum(vector<int> &numbers, int target) {
		 int n = numbers.size();
		 multimap<int , int> findmap;
		 std::vector<int> sol;
		 multimap <int , int> :: iterator it;

		 for(int i = n-1 ;i>=0 ; i--){
			 findmap.insert(pair<int , int>(numbers[i] , i));
			 it = findmap.find(target-numbers[i]);
			 if(it != findmap.end() && (numbers[i]+ it->first == target) && i < it->second){
				 // index1 = i and index2 = it->second;
				 sol.push_back(i+1);
				 sol.push_back(it->second+1);
			 }
		 }
		 return sol;
	 }
 };