#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		bool valid(int rem, int target, map<int, int> &cnt) {
			if (rem == target) {
				if (cnt[rem] >= 2) return true;
				else return false;
			} else {
				if (cnt[rem]) return true;
				return false;
			}
		}
		vector<int> get_ans(vector<int> &num, map<int, vector<int> > &pos) {
			vector<int> ans;
			for (int i = 0; i < num.size(); i++) {
				ans.push_back(pos[num[i]][pos[num[i]].size() - 1]);
				pos[num[i]].pop_back();
			}
			sort(ans.begin(), ans.end());
			return ans;
		}

	public:
		vector<int> twoSum(vector<int> &num, int target) {
			map<int, int> cnt;
			map<int, vector<int> > pos;
			for (int i = 0; i < num.size(); i++) {
				cnt[num[i]]++;
				pos[num[i]].push_back(i);
			}
			vector<int> ans = {};
			vector<int> candidate_soln = {};
			for (int i = 0; i < num.size(); i++) {
				int rem = target - num[i];
				if (valid(rem, num[i], cnt)) {
					candidate_soln.push_back(rem);
					candidate_soln.push_back(num[i]);
					return get_ans(candidate_soln, pos);
				}
			}
			return vector<int>();
		}
};
