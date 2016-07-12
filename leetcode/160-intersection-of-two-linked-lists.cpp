/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (headA == NULL || headB == NULL) return NULL;
			int lenA = 0, lenB = 0;
			ListNode* currA = headA;
			ListNode* currB = headB;
			while (currA) {
				currA = currA->next;
				lenA++;
			}
			while (currB) {
				currB = currB->next;
				lenB++;
			}
			currA = headA;
			currB = headB;
			while (lenA > lenB) {
				currA = currA->next;
				lenA--;
			}
			while (lenB > lenA) {
				currB = currB->next;
				lenB--;
			}
			while (currA && currA != currB) {
				currA = currA->next;
				currB = currB->next;
			}
			return currA;
		}
};
