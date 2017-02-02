#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
	public:
	unordered_map<int, UndirectedGraphNode*> hashmap;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) { return NULL; }

		unordered_map<int, UndirectedGraphNode*>::iterator it;
		if ((it = hashmap.find(node->label)) != hashmap.end()) {
			return it->second;
		}

		UndirectedGraphNode *pn = new UndirectedGraphNode(node->label);
		hashmap[node->label] = pn;
		pn->neighbors.resize(node->neighbors.size(), NULL);

		for (int i=0, end=node->neighbors.size(); i<end; ++i) {
			pn->neighbors[i] = cloneGraph(node->neighbors[i]);
		}

		return pn;
	}
};
