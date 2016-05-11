class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int len = s.length();
			map<char, int> mp;
			int left = 0, right = 0;
			int ansleft = 0 , ansright = 0;
			for (int i = 0; i < len; i++) {
				while (mp[s[i]] > 0) {
					mp[s[left]]--;
					left++;
				}
				mp[s[i]]++;
				right++;
				if (ansright - ansleft < right - left) {
					ansright = right;
					ansleft = left;
				}
			}
			return ansright - ansleft;
		}
};
