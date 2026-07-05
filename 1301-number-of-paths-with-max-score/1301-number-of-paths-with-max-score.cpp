class Solution {

    int n;
    int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> dp;

    int getIntFromChar(char ch) { // converts char to int, for Start position return 0
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, vector<string>& board) {
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }

    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (board[i][j] == 'E') // found one path that reaches end
            return {0, 1};
        if (board[i][j] == 'X') // no valid path if obstacle found
            return {0, 0};

        if (dp[i][j] != make_pair(-1, -1))
            return dp[i][j];

        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;
        char ch = board[i][j];

        if (isValid(i - 1, j, board)) { // move up
            auto [score, paths] = solve(i - 1, j, board);
            upScore = score;
            upPaths = paths;
            if (upPaths > 0)
                upScore += getIntFromChar(ch);
        }
        if (isValid(i, j - 1, board)) { // move left
            auto [score, paths] = solve(i, j - 1, board);
            leftScore = score;
            leftPaths = paths;
            if (leftPaths > 0)
                leftScore += getIntFromChar(ch);
        }
        if (isValid(i - 1, j - 1, board)) { // move up-left (diagonal)
            auto [score, paths] = solve(i - 1, j - 1, board);
            diagScore = score;
            diagPaths = paths;
            if (diagPaths > 0)
                diagScore += getIntFromChar(ch);
        }

        int bestScore, bestPaths;
        if (upScore == leftScore && leftScore == diagScore) { // all 3 direction same score
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        } 
        else if (upScore == leftScore) { // 2 direction same score
            bestScore = upScore; 
            bestPaths = upPaths + leftPaths;
            if (diagScore > bestScore) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        } 
        else if (leftScore == diagScore) { // 2 direction same score
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;
            if (upScore > bestScore) {
                bestScore = upScore; bestPaths = upPaths;
            }
        } 
        else if (upScore == diagScore) { // 2 direction same score
            bestScore = upScore;
            bestPaths = upPaths + diagPaths;
            if (leftScore > bestScore) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
        } 
        else { // no direction same score
            bestScore = upScore; bestPaths = upPaths;
            if (leftScore > bestScore) {
                bestScore = leftScore; bestPaths = leftPaths;
            }
            if (diagScore > bestScore) {
                bestScore = diagScore; bestPaths = diagPaths;
            }
        }

        dp[i][j] = {bestScore, bestPaths % MOD};
        return dp[i][j];
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        
        dp.assign(n, vector<pair<int,int>>(n, {-1, -1}));

        auto result = solve(n - 1, n - 1, board);
        return {result.first, result.second};
    }
};

//(Recursion + DP Memoization)
// O(n^2) O(n^2)
// for each node we have 3 choices up, left, top left diag
// then comparing all 3 scores and paths to find the highest
// and if multiple paths contributed to highest score to add 
// up their contribution