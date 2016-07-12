class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			string longest = "";
			if (strs.size() == 0) return longest;
			int curr = 0;
			bool terminate = false;
			while (!terminate) {
				if (curr >= strs[0].length()) {
					terminate = true;
				} else {
					for (int i = 1; i < strs.size(); i++) {
						if (curr >= strs[i].length() || strs[i][curr] != strs[0][curr]) {
							terminate = true;
							break;
						}
					}
				}
				if (!terminate) {
					longest = longest + strs[0][curr++];
				}
			}
			return longest;
		}
};
