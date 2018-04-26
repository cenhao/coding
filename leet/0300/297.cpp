/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string out = "[";
		bool first = true;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			auto *cur = q.front();
			q.pop();
			if (cur != nullptr) {
				if (!first) {
					out += ',';
				} else {
					first = false;
				}
				out += to_string(cur->val);
				q.push(cur->left);
				q.push(cur->right);
			} else if (!q.empty()) {
				if (!first) {
					out += ',';
				} else {
					first = false;
				}
				out += "null";
			}
		}
		out += "]";
		return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		if (data.length() <= 2) { return nullptr; }
		TreeNode *cur = nullptr;
		queue<TreeNode**> q;
		q.push(&cur);
		int pos = 0;
		while (data[pos]!=']' && !q.empty()) {
			++pos;
			TreeNode **tmp = q.front();
			q.pop();
			if (data[pos] == 'n') {
				*tmp = nullptr;
				pos += 4;
			} else {
				bool neg = false;
				if (data[pos] == '-') {
					neg = true;
					++pos;
				}
				int v = 0;
				while (data[pos]>='0' && data[pos]<='9') {
					v = v * 10 + data[pos++]-'0';
				}
				if (neg) { v = -v; }
				*tmp = new TreeNode(v);
				q.push(&((*tmp)->left));
				q.push(&((*tmp)->right));
			}
		}
		return cur;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
