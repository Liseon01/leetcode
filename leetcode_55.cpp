class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int maxReach = 0;  // 현재 갈 수 있는 최대 거리
            for (int i = 0; i < nums.size(); i++) {
                if (i > maxReach) return false;  // 현재 위치가 도달할 수 없는 경우
                maxReach = max(maxReach, i + nums[i]);  // 최대 도달 가능 위치 갱신
            }
            return true;
        }
    };
    