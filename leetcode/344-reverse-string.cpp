class Solution {
	private:
		int inv(int idx, int len) {
			return len - idx - 1;
		}

	public:
		string reverseString(string s) {
			int len = s.length();
			for (int i = 0; i < len / 2; i++) {
				s[i] ^= s[inv(i, len)] ^= s[i] ^= s[inv(i, len)];
			}
			return s;
		}
};
