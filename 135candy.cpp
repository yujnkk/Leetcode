class Solution {  
public:  
	int* candies;  
	int candy(vector<int> &ratings) {  
		candies = new int[ratings.size()];  
		for(int i = 0; i < ratings.size(); i++){  
			candies[i] = 1;  
		}  

		for(int i = ratings.size() - 1; i > 0; i--){  
			if(ratings[i] < ratings[i - 1]){  
				candies[i - 1] = candies[i] + 1;  
			}  
		}  

		for(int i = 0; i < ratings.size() - 1; i++){  
			if(ratings[i] < ratings[i + 1]){  
				int tmp = candies[i] + 1;  
				if(candies[i + 1] < tmp){  
					candies[i + 1] = tmp;  
				}  
			}  
		}  

		int sum = 0;  
		for(int i = 0; i < ratings.size(); i++){  
			sum += candies[i];  
		}  

		return sum;  
	}  
};