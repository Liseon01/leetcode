class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> result;
            vector<string> board(n, string(n, '.')); // n x n 체스판 초기화
            backtrack(result, board, 0, n);
            return result;
        }
    
    private:
        void backtrack(vector<vector<string>>& result, vector<string>& board, int row, int n) {
            if (row == n) {
                result.push_back(board); // 모든 퀸을 배치 완료 → 결과 저장
                return;
            }
    
            for (int col = 0; col < n; col++) {
                if (isValid(board, row, col, n)) { 
                    board[row][col] = 'Q'; // 퀸 배치
                    backtrack(result, board, row + 1, n); // 다음 행 탐색
                    board[row][col] = '.'; // 백트래킹 (원상복구)
                }
            }
        }
    
        bool isValid(vector<string>& board, int row, int col, int n) {
            // 같은 열 체크
            for (int i = 0; i < row; i++) {
                if (board[i][col] == 'Q') return false;
            }
    
            // 좌상향 대각선 체크 (`/` 방향)
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }
    
            // 우상향 대각선 체크 (`\` 방향)
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }
    
            return true;
        }
    };
    