class TrieNode {
	public:
		bool isWord;
		TrieNode* children[26];
		// Initialize your data structure here.
		TrieNode() {
			isWord = false;
			for (int i = 0; i < 26; i++) children[i] = NULL;
		}
};

class Trie {
	public:
		Trie() {
			root = new TrieNode();
		}

		// Inserts a word into the trie.
		void insert(string word) {
			int len = word.length();
			TrieNode* curr = root;
			for (int i = 0; i < len; i++) {
				int idx = word[i] - 'a';
				if (curr->children[idx] == NULL) {
					curr->children[idx] = new TrieNode();
				}
				curr = curr->children[idx];
			}
			curr->isWord = true;
		}

		// Returns if the word is in the trie.
		bool search(string word) {
			int len = word.length();
			TrieNode* curr = root;
			for (int i = 0; i < len; i++) {
				int idx = word[i] - 'a';
				if (curr->children[idx] == NULL) {
					return false;
				}
				curr = curr->children[idx];
			}
			return curr->isWord;
		}

		// Returns if there is any word in the trie
		// that starts with the given prefix.
		bool startsWith(string prefix) {
			int len = prefix.length();
			TrieNode* curr = root;
			for (int i = 0; i < len; i++) {
				int idx = prefix[i] - 'a';
				if (curr->children[idx] == NULL) {
					return false;
				}
				curr = curr->children[idx];
			}
			return true;
		}

	private:
		TrieNode* root;
};

// Your Trie object will be instantiated and called as such:

// Trie trie;

// trie.insert("somestring");

// trie.search("key");
