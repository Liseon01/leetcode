class Solution {
    public:
        int jump(vector<int>& nums) {
            
        int n = nums.size();
        if (n == 1) return 0; // 이미 목적지에 도달한 경우
    
        int jumps = 0;
        int farthest = 0;
        int current_jump_end = 0;
    
        for (int i = 0; i < n - 1; i++) { // 마지막 인덱스 전까지만 탐색
            farthest = max(farthest, i + nums[i]); // 가장 멀리 갈 수 있는 위치 갱신
    
            if (i == current_jump_end) { // 현재 점프 범위의 끝이면 점프 실행
                jumps++;
                current_jump_end = farthest; // 다음 점프의 최대 범위 갱신
                
                if (current_jump_end >= n - 1) break; // 목적지 도달 시 종료
            }
        }
        
        return jumps;
        }
    };