#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target) {
			map<int, int> mp;
			for (int i = 0; i < nums.size(); i++) {
				int complement = target - nums[i];
				map<int, int>::iterator it = mp.find(complement);
				if (it != mp.end()) {
					return {it->second, i};
				}
				mp.insert({nums[i], i});
			}
			return {};
		}
};

int main() {
	Solution *s = new Solution();
	vector<int> nums;
	for (int i = 0; i < 10; i++) nums.push_back(i);
	vector<int> ans = s->twoSum(nums, 3);
	for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
