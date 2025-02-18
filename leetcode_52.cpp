class Solution {
    public:
        int totalNQueens(int n) {
            int result = 0;
            vector<int> Q(n, -1);  // Q의 크기를 n으로 초기화
            backtrack(result, Q, 0, n);
            return result;
        }
    
        void backtrack(int& result, vector<int>& Q, int row, int n)
        {
            if (row == n) {
                result++;
                return;
            }
    
            for(int cols = 0; cols < n; cols++) {  
                bool legal = true;
    
                for(int i = 0; i < row; i++) {
                    if(Q[i] == cols || abs(Q[i] - cols) == abs(row - i)) {  // 대각선 체크 
                        legal = false;
                        break;  // 불필요한 반복 방지
                    }
                }
    
                if (legal) {
                    Q[row] = cols;
                    backtrack(result, Q, row + 1, n);
                    Q[row] = -1;  // 백트래킹 후 원상 복구
                }
            }
        }
    };
    