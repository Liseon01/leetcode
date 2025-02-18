class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> result;
            if (matrix.empty() || matrix[0].empty()) return result;
            
            int top = 0;
            int bottom = matrix.size() - 1;
            int left = 0;
            int right = matrix[0].size() - 1;
            
            while (top <= bottom && left <= right) {
                // 왼쪽 → 오른쪽 이동
                for (int j = left; j <= right; j++) {
                    result.push_back(matrix[top][j]);
                }
                top++;
                
                // 위 → 아래 이동
                for (int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
                
                // 아래쪽 행이 남아있다면 오른쪽 → 왼쪽 이동
                if (top <= bottom) {
                    for (int j = right; j >= left; j--) {
                        result.push_back(matrix[bottom][j]);
                    }
                    bottom--;
                }
                
                // 왼쪽 열이 남아있다면 아래 → 위 이동
                if (left <= right) {
                    for (int i = bottom; i >= top; i--) {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                }
            }
            
            return result;
        }
    };
    