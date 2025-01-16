class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        // 1. 입력 배열 정렬
        sort(nums.begin(), nums.end());

        // 2. ThreeSum 계산
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 중복 제거

            int target = -nums[i]; // nums[i]에 대한 타겟 값
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // 중복 제거
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};
