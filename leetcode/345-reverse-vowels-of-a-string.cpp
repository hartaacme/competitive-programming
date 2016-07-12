class Solution {
	private:
		char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

		void swap(char &c1, char &c2) {
			c1 ^= c2 ^= c1 ^= c2;
		}

		char lower(char c) {
			if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
			return c;
		}

		bool vowel(char c) {
			c = lower(c);
			for (auto &it: vowels) {
				if (it == c) return true;
			}
			return false;
		}

	public:
		string reverseVowels(string s) {
			int len = s.length(), left = 0, right = len - 1;
			while (left < right) {
				while (left < len && !vowel(s[left])) left++;
				while (right >= 0 && !vowel(s[right])) right--;
				if (left < right) swap(s[left], s[right]);
				left++;
				right--;
			}
			return s;
		}
};
