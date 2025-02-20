class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> arr(n, vector<int>(n, 0)); // 초기화
    
            int top = 0, bottom = n - 1, left = 0, right = n - 1;
            int index = 1; // 숫자는 1부터 시작
    
            while (left <= right && top <= bottom) {
                for (int i = left; i <= right; i++) { // → 방향
                    arr[top][i] = index++;
                }
                top++;
    
                for (int i = top; i <= bottom; i++) { // ↓ 방향
                    arr[i][right] = index++;
                }
                right--;
    
                if (top <= bottom) { // ← 방향
                    for (int i = right; i >= left; i--) {
                        arr[bottom][i] = index++;
                    }
                    bottom--;
                }
    
                if (left <= right) { // ↑ 방향
                    for (int i = bottom; i >= top; i--) {
                        arr[i][left] = index++;
                    }
                    left++;
                }
            }
    
            return arr;
        }
    };
    