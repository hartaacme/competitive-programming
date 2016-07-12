/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
	private:
		int popCount = 2;
		vector<ListNode*> remove(stack<ListNode*> &stk) {
			vector<ListNode*> ans;
			for (int i = 0; i < popCount; i++) {
				ans.push_back(stk.top());
				stk.pop();
			}
			return ans;
		}

	public:
		ListNode* swapPairs(ListNode* head) {
			if (head == NULL) return head;
			stack<ListNode*> stk;
			ListNode *curr = head;
			int tot = 0;
			while (curr) {
				stk.push(curr);
				curr = curr->next;
				tot++;
			}

			ListNode *last = NULL;
			int remainder = tot % popCount;
			if (remainder) {
				for (int i = 0; i < remainder; i++) {
					last = stk.top();
					stk.pop();
				}
			}

			while (!stk.empty()) {
				vector<ListNode*> v = remove(stk);
				for (int i = 0; i < v.size() - 1; i++) {
					v[i]->next = v[i + 1];
				}
				v[v.size() - 1]->next = last;
				last = v[0];
			}
			return last;
		}
};
