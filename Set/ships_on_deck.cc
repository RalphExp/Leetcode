/* LC: 419, solution 1 */

class Solution1 {
public:
    void processQueue(vector<vector<char>>& board, queue<pair<int, int>> &q) {
        while (q.size()) {
            auto front = q.front();
            q.pop();

            auto i = front.first;
            auto j = front.second;
            board[i][j] = '.';

            if (i > 0 && board[i][j] == 'X')
                q.push(pair<int, int>(i-1, j));
            if (i < board.size()-1 && board[i+1][j] == 'X')
                q.push(pair<int, int>(i+1, j));
            if (j > 0 && board[i][j-1] == 'X')
                q.push(pair<int, int>(i, j-1));
            if (j < board[0].size()-1 && board[i][j+1] == 'X')
                q.push(pair<int, int>(i, j+1));
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        cnt_ = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    q.push(pair<int, int>(i, j));
                    ++cnt_;
                    processQueue(board, q);
                }
            }
        }
        return cnt_;
    }

private:
    int cnt_;
};

/* LC: 419, solution 2 */
class Solution2 {
public:
    int countBattleships(vector<vector<char>>& board) {
        cnt_ = 0;

        for (int i = 0; i < board.size(); ++i) {
            int j = 0;

            while (j < board[0].size()) {
                if (board[i][j] == 'X') {
                    if (i < board.size()-1 && board[i+1][j] == 'X') {
                        ; // do nothing we can count it in next round
                    } else {
                        ++cnt_;
                        while (++j < board[0].size() && board[i][j] == 'X');
                    }
                }
                ++j;
            }
        }
        return cnt_;
    }

private:
    int cnt_;
};
