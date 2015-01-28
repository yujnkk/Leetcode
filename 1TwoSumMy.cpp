class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int>::iterator begin,end;
        begin = numbers.begin();
        end = numbers.end();
        int index1 = 1,index2 = end -begin;
        end --;
        while((*begin+*end != target)||begin == end)
        {
            if(begin==end||*end > target)
            {
                end--;
                begin = numbers.begin();
                index1 = 1;
                index2 --;
                continue;
            }
            begin ++;
            index1++;
        }
        vector<int> result;
        result.push_back(index1);
        result.push_back(index2);
        return result;
    }
};