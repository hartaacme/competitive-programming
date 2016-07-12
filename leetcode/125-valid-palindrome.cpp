class Solution {
	private:
		char lower(char c) {
			if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
			return c;
		}

		bool isAlphabet(char c) {
			return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
		}

	public:
		bool isPalindrome(string s) {
			int len = s.length(), left = 0, right = len - 1;
			while (left < right) {
				while (left < len && !isAlphabet(s[left])) left++;
				while (right >= 0 && !isAlphabet(s[right])) right--;
				if (left < right) {
					s[left] = lower(s[left]);
					s[right] = lower(s[right]);
					if (s[left] != s[right]) return false;
					left++;
					right--;
				}
			}
			return true;
		}
};
