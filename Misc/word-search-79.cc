class Solution {
public:
    bool search(vector<vector<char>>&board, int i, int j) {
        // printf("i:%d, j:%d", i, j);

        if (v[i][j] == 1 || board[i][j] != s[idx])
            return false;

        if (++idx == s.size())
            return true;
        v[i][j] = 1;

        if (i > 0) {
            if (search(board, i-1, j))
                return true;
        }
        if (i < board.size() - 1) {
            if (search(board, i+1, j))
                return true;
        }
        if (j > 0) {
            if (search(board, i, j-1))
                return true;
        }
        if (j < board[0].size() - 1) {
            if (search(board, i, j+1))
                return true;
        }

        --idx;
        v[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        v = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        s = word;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                idx = 0;
                bool e = search(board, i, j);
                if (e)
                    return true;
            }
        }
        return false;
    }

public:
    vector<vector<int>> v;
    string s;
    int idx;
};
