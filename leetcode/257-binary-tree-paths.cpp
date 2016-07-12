/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
	private:
		string toStr(int x) {
			if (x == 0) return "0";
			string res = "";
			bool neg = false;
			if (x < 0) {
				neg = true;
				x *= -1;
			}
			while (x) {
				res = (char)(x % 10 + '0') + res;
				x /= 10;
			}
			if (neg) res = "-" + res;
			return res;
		}

	public:
		vector<string> binaryTreePaths(TreeNode* root) {
			vector<string> ans;
			if (root == NULL) return ans;
			queue<pair<TreeNode*, string> > q;
			q.push({root, ""});
			while (!q.empty()) {
				pair<TreeNode*, string> front = q.front();
				q.pop();
				TreeNode* currNode = front.first;
				string nodeStr = front.second;
				if (currNode->left == NULL && currNode->right == NULL) {
					ans.push_back(nodeStr + (nodeStr != "" ? "->" : "") + toStr(currNode->val));
					continue;
				}
				if (currNode->left != NULL) q.push({currNode->left, nodeStr + (nodeStr != "" ? "->" : "") + toStr(currNode->val)});
				if (currNode->right != NULL) q.push({currNode->right, nodeStr + (nodeStr != "" ? "->" : "") + toStr(currNode->val)});
			}
			return ans;
		}
};
