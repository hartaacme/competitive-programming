class Solution {
	public:
		vector<int> countBits(int num) {
			vector<int> ans;
			vector<int> curr;
			curr.push_back(0);
			ans.push_back(0);
			int cnt = 0;
			for (int i = 1; i <= num; i++) {
				int carry = 1;
				for (int j = 0; j < curr.size() && carry; j++) {
					if (curr[j] == 1) cnt--;
					curr[j] = curr[j] + carry;
					carry = curr[j] / 2;
					curr[j] = curr[j] % 2;
					if (curr[j] == 1) cnt++;
				}
				if (carry) {
					curr.push_back(carry);
					cnt++;
				}
				ans.push_back(cnt);
			}
			return ans;
		}
};
