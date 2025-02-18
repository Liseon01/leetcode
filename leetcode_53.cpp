// 더하기와 결과값을 같이 계산
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int currentSum = nums[0];
            int maxSum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                currentSum = max(nums[i], currentSum + nums[i]);
                maxSum = max(maxSum, currentSum);
            }
            return maxSum;
        }
    };
    