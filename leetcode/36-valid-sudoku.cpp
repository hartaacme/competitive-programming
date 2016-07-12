class Solution {
	private:
		bool check(vector<vector<char> > &board, int x, int y, vector<bool> &used) {
			if (board[x][y] == '.') return true;
			int num = board[x][y] - '0';
			if (used[num]) return false;
			used[num] = true;
			return true;
		}

	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			int n = board.size();
			if (n != 9) return false;
			int m = board[0].size();
			if (m != 9) return false;
			// check horizontal
			vector<bool> used;
			used.resize(10);

			bool result;
			for (int i = 0; i < n; i++) {
				fill(used.begin(), used.end(), false);
				for (int j = 0; j < m; j++) {
					result = check(board, i, j, used);
					if (!result) return false;
				}
			}

			// check vertical
			for (int i = 0; i < n; i++) {
				fill(used.begin(), used.end(), false);
				for (int j = 0; j < m; j++) {
					result = check(board, j, i, used);
					if (!result) return false;
				}
			}

			// check 3 x 3
			for (int i = 0; i < n; i+=3) {
				for (int j = 0; j < m; j+=3) {
					fill(used.begin(), used.end(), false);
					for (int k = i; k < i + 3; k++) {
						for (int l = j; l < j + 3; l++) {
							result = check(board, k, l, used);
							if (!result) return false;
						}
					}
				}
			}
			return true;
		}
};
