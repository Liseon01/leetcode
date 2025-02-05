class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
    // 행 검사
    for (int i = 0; i < 9; i++) {
        bool seen[10] = { false };  // 1~9를 저장 (인덱스 0은 사용하지 않음)
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {  // 빈칸이 아닌 경우
                int num = board[i][j] - '0';  // char -> int 변환
                if (seen[num]) {
                    // 이미 등장한 숫자이면 잘못된 보드
                    return false;
                }
                seen[num] = true;
            }
        }
    }

    // 열 검사
    for (int j = 0; j < 9; j++) {
        bool seen[10] = { false };
        for (int i = 0; i < 9; i++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0';
                if (seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }
    }

    // 3×3 서브박스 검사
    // 9개의 박스를 각각 검사합니다.
    for (int block = 0; block < 9; block++) {
        bool seen[10] = { false };
        // 각 블록의 시작 행과 시작 열
        int rowStart = (block / 3) * 3;
        int colStart = (block % 3) * 3;
        for (int i = rowStart; i < rowStart + 3; i++) {
            for (int j = colStart; j < colStart + 3; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (seen[num]) {
                        return false;
                    }
                    seen[num] = true;
                }
            }
        }
    }

    // 모든 검사 통과 시 유효한 스도쿠 보드입니다.
    return true;
    }
};