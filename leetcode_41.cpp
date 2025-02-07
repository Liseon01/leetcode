class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); 
        
        // 1. 음수는 0으로 변환
        for (int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                nums[i] = 0;
            }
        }
        
        // 2. 인덱스 마킹: 절댓값을 사용해서 1~n 범위의 수가 존재함을 표시
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);  // 반드시 절댓값을 사용!
            if(val >= 1 && val <= n) {
                if(nums[val - 1] > 0) {  // 아직 마킹되지 않은 경우
                    nums[val - 1] = -nums[val - 1];
                }
                else if(nums[val - 1] == 0) {  // 이미 0이라면, 확실한 음수값 할당
                    nums[val - 1] = -(n + 1);
                }
                // 만약 이미 음수이면(이미 마킹된 경우) 아무 처리도 하지 않음
            }
        }
        
        // 3. 가장 작은 누락된 양의 정수 찾기
        for (int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                return i + 1;  // 인덱스 i는 실제 값 i+1에 해당
            }
        }
        return n + 1;
    }
};
