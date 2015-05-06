class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> fromStart, fromEnd;
        unordered_set<string> frontierStart, frontierEnd;
        fromStart.push(start);
        fromEnd.push(end);
        frontierStart.insert(start);
        frontierEnd.insert(end);
        int dist=1;

        while(!fromStart.empty()&&!fromEnd.empty()){
            if(fromStart.size()<=fromEnd.size()){
                if(stepForward(fromStart, dict, frontierStart, frontierEnd)) return dist + 1;
            }else{
                if(stepForward(fromEnd, dict, frontierEnd, frontierStart)) return dist + 1;
            }
            dist++;
        }
        return 0;
    }
    bool stepForward(queue<string> &levelQ, unordered_set<string> &dict,
                        unordered_set<string> &frontSelf, unordered_set<string> &frontOther){
        queue<string> nextLevelQ;
        frontSelf.clear();
        while(!levelQ.empty()){
            string currWord = levelQ.front(); levelQ.pop();
            for(int i=0;i<currWord.size();i++){
                for(char newC='a';newC<='z';newC++){
                    string nextWord=currWord;
                    nextWord[i]=newC;
                    if(frontOther.count(nextWord)>0) return true;
                    if(dict.count(nextWord)>0){
                        dict.erase(nextWord);
                        nextLevelQ.push(nextWord);
                        frontSelf.insert(nextWord);
                    }
                }            
            }
        }
        levelQ.swap(nextLevelQ);
        return false;
    }
};