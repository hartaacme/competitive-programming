class Solution {
	public:
		int lengthOfLastWord(string s) {
			int len = s.length();
			int cnt = 0, lastCnt = 0;
			for (int i = 0; i < len; i++) {
				if (s[i] == ' ') {
					if (cnt != 0) {
						lastCnt = cnt;
					}
					cnt = 0;
				} else cnt++;
			}
			if (cnt != 0) lastCnt = cnt;
			return lastCnt;
		}
};
