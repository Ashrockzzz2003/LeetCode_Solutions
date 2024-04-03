class Solution {
public:
    bool dfsSearch(vector<vector<char>>& board, string word, int i, int j, int k) {
        // a b c e
        // s f c s
        // a d e e

        // we've found a possible match.
        if (k == word.length()) {
            return true;
        }

        // cout << i << " " << j << " " << word[k] << endl;

        // out of bounds or word mismatch.
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
            return false;
        }

        board[i][j] = '8';

        bool dfs_search = dfsSearch(board, word, i + 1, j, k + 1) || dfsSearch(board, word, i, j + 1, k + 1) || dfsSearch(board, word, i - 1, j, k + 1) || dfsSearch(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];

        return dfs_search;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if (word[0] == board[i][j] && dfsSearch(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};