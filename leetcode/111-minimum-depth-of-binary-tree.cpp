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
	public:
		int minDepth(TreeNode* root) {
			if (root == NULL) return false;
			queue<TreeNode*> q;
			q.push(root);
			map<TreeNode*, int> mp;
			mp[root] = 1;

			int ans = 1000000000;
			while (!q.empty()) {
				TreeNode* front = q.front();
				q.pop();
				if (front->left == NULL && front->right == NULL) {
					ans = min(ans, mp[front]);
					continue;
				}
				if (front->left != NULL) {
					mp[front->left] = 1 + mp[front];
					q.push(front->left);
				}

				if (front->right != NULL) {
					mp[front->right] = 1 + mp[front];
					q.push(front->right);
				}
			}
			return ans;
		}
};
