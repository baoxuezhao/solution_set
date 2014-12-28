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
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return dfs(node, map);
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &map) {
        if(node == NULL) return NULL;
        if(map.find(node) != map.end())
            return map[node];
        
        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        map[node] = newnode;
        
        for(int i=0; i<node->neighbors.size(); i++)
        {
            UndirectedGraphNode *nei = dfs(node->neighbors[i], map);
            newnode->neighbors.push_back(nei);
        }
        return newnode;
    }
};
