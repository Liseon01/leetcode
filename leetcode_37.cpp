#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
    
private:
    // 백트래킹 함수: 스도쿠를 완성할 수 있으면 true, 그렇지 않으면 false 반환
    bool backtrack(vector<vector<char>>& board) {
        // 모든 칸을 순회하며 빈 칸('.')을 찾음
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    // '1'부터 '9'까지 시도
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;  // 후보 숫자 배치
                            
                            // 재귀적으로 다음 빈 칸 채우기
                            if (backtrack(board))
                                return true;
                            
                            // 이후 진행이 불가능하면, 해당 숫자 배치를 취소(백트래킹)
                            board[i][j] = '.';
                        }
                    }
                    // 해당 빈 칸에 올 수 있는 숫자를 모두 시도했지만 문제 해결이 불가능하면 false 반환
                    return false;
                }
            }
        }
        // 모든 칸을 채웠다면 스도쿠 완성
        return true;
    }
    
    // 해당 위치 (row, col)에 숫자 c를 배치할 수 있는지 검사
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // 같은 행에 c가 이미 존재하는지 검사
            if (board[row][i] == c)
                return false;
            // 같은 열에 c가 이미 존재하는지 검사
            if (board[i][col] == c)
                return false;
            // 해당 칸이 속한 3×3 박스 내에서 c가 존재하는지 검사
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c)
                return false;
        }
        return true;
    }
};
