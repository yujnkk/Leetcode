/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL)
			return NULL;
		queue<UndirectedGraphNode*> q;
		map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
		mp[node] = new UndirectedGraphNode(node -> label);
		q.push(node);
		while(!q.empty())
		{
			UndirectedGraphNode *temp = q.front();
			q.pop();
			for(int i = 0; i < temp -> neighbors.size(); ++ i)
			{
				if(mp[temp -> neighbors[i]] == NULL)
				{
					mp[temp -> neighbors[i]] = new UndirectedGraphNode(temp -> neighbors[i] -> label);
					q.push(temp -> neighbors[i]);
				}
				(mp[temp]->neighbors).push_back(mp[temp -> neighbors[i]]);
			}
		}
		return mp[node];
	}
};