class Solution {
	public:
		bool isIsomorphic(string s, string t) {
			int lenS = s.length();
			int lenT = t.length();
			if (lenS != lenT) return false;
			map<char, char> mp, mp2;
			for (int i = 0; i < lenS; i++) {
				if (mp.find(s[i]) == mp.end() && mp2.find(t[i]) == mp2.end()) {
					mp[s[i]] = t[i];
					mp2[t[i]] = s[i];
				}
				if (mp[s[i]] != t[i] || mp2[t[i]] != s[i]) return false;
			}
			return true;
		}
};
