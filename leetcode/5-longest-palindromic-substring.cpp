class Solution {
	private:
		pair<int, int> getPalin(string &s, int start, int end) {
			int len = s.length();
			pair<int, int> ans;
			while (start >= 0 && end < len) {
				if (s[start] == s[end]) {
					ans = {start, end};
				} else {
					break;
				}
				start--;
				end++;
			}
			return ans;
		}

	public:
		string longestPalindrome(string s) {
			int len = s.length();
			if (len == 0) return s;
			int maxLen = 0;
			pair<int, int> ans = {0, 0};
			// odd
			for (int i = 0; i < len; i++) {
				pair<int, int> cand = getPalin(s, i, i);
				if (cand.second - cand.first > ans.second - ans.first) {
					ans = cand;
				}
			}
			for (int i = 1; i < len; i++) {
				if (s[i - 1] == s[i]) {
					pair<int, int> cand = getPalin(s, i - 1, i);
					if (cand.second - cand.first > ans.second - ans.first) {
						ans = cand;
					}
				}
			}
			return s.substr(ans.first, ans.second - ans.first + 1);
		}
};
